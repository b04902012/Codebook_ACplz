#include<algorithm>
#include<math.h>
#include<vector>
#include<stdio.h>
#define PB push_back
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;

typedef double db;
const db INF=1e9;
const db EPS=1e-10;
const db PI=acos((db)-1);

bool gt(db a,db b){return a>b+b*EPS;}
bool lt(db a,db b){return a<b-b*EPS;}
bool eq(db a,db b){return !gt(a,b)&&!lt(a,b);}

struct Pt {
    db x,y;
    Pt(){}
    Pt(db x,db y):x(x),y(y){}
    db angle()const{
        db a=atan2(y,x);
        if(lt(a,0))a+=2*PI;
        return a;
    }
    db norm()const{return sqrt(x*x+y*y);}
    Pt rtt(db t)const{return Pt(x*cos(t)-y*sin(t),x*sin(t)+y*cos(t));}
    void print()const{printf("x=%lf, y=%lf\n",x,y);}
};
const Pt ERR=Pt(1e100,1e100);
Pt operator-(Pt a,Pt b){return Pt(a.x-b.x,a.y-b.y);}
Pt operator+(Pt a,Pt b){return Pt(a.x+b.x,a.y+b.y);}
Pt operator*(Pt p,db k){return Pt(p.x*k,p.y*k);}
Pt operator/(Pt p,db k){return Pt(p.x/k,p.y/k);}
db operator*(Pt a,Pt b){return a.x*b.x+a.y*b.y;}
db operator^(Pt a,Pt b){return a.x*b.y-a.y*b.x;}
bool operator==(Pt a,Pt b){return eq(a.x,b.x)&&eq(a.y,b.y);}
bool operator!=(Pt a,Pt b){return !(a==b);}
bool prl(Pt a,Pt b){return eq(atan2(a.y,a.x),atan2(b.y,b.x));}

struct Sg{
    Pt s,t;
    Sg(){}
    Sg(Pt s,Pt t):s(s),t(t){}
    Sg(double a,double b,double c,double d):s(a, b),t(c,d){}
    Pt vtr()const{return t-s;};
    bool on(Pt p,bool range=true)const{return prl(p-s,p-t)&&!gt((p-s)*(p-t),0);}
    void print()const{
        puts("s:");s.print();
        puts("t:");t.print();
    }
};

struct Pg{
    vector<Pt>lst;
    Pg(){}
    Pg(vector<Pt>tlst){lst=tlst;lst.PB(lst[0]);}

    db area(){
        int l=lst.size();
        db a=0.0;
        for(int i=0;i<l;i++)a+=lst[i]^lst[i+1];
        a/=2.0;
        return a;
    }
    void sort(){
        if(lt(area(),0))reverse(lst.begin(),lst.end());
    }
};

Pt intersect(Sg a,Sg b,bool range=true){
    Pt p;
    db xa=a.s.y-a.t.y;db ya=a.t.x-a.s.x;
    db ka=xa*a.s.x+ya*a.s.y;
    db xb=b.s.y-b.t.y;db yb=b.t.x-b.s.x;
    db kb=xb*b.s.x+yb*b.s.y;
    if(eq((Pt(xa,ya)^Pt(xb,yb)),0.0))return ERR;
    p.x=(Pt(ya,yb)^Pt(ka,kb))/(Pt(ya,yb)^Pt(xa,xb));
    p.y=(Pt(xa,xb)^Pt(ka,kb))/(Pt(xa,xb)^Pt(ya,yb));
    if(!range)return p;
    if(a.on(p)&&b.on(p))return p;
    return ERR;
}

bool inPlane(Sg a,Pt p){return p!=ERR&&!gt((a.t-p)^(a.s-p),0);}

bool cmp(const Sg &a,const Sg &b){
    if(!eq(a.vtr().angle(),b.vtr().angle()))return a.vtr().angle()<b.vtr().angle();
    return gt((b.t-a.s)^a.vtr(),0);
}
Sg dq[200];
void halfPlaneIntersect(vector<Sg>v,vector<Sg>&res){
    v.PB(Sg(Pt(INF/2.0,-INF/2.0),Pt(INF/2.0,INF/2.0)));
    v.PB(Sg(Pt(INF/2.0,INF/2.0),Pt(-INF/2.0,INF/2.0)));
    v.PB(Sg(Pt(-INF/2.0,INF/2.0),Pt(-INF/2.0,-INF/2.0)));
    v.PB(Sg(Pt(-INF/2.0,-INF/2.0),Pt(INF/2.0,-INF/2.0)));
    sort(v.begin(),v.end(),cmp);
    int j=0,l=v.size();
    for(int i=1;i<l;i++){
        if(!eq(v[i].vtr().angle(),v[j].vtr().angle())){
            j++;
            v[j]=v[i];
        }
    }
    v.resize(j+1);
    int n=v.size();

    dq[0]=v[0];
    dq[1]=v[1];
    int top=1;
    int bot=0;
    for(int i=2;i<n;i++){
        while(top>bot&&!inPlane(v[i],intersect(dq[top],dq[top-1],false))){
            top--;
        }
        while(top>bot&&!inPlane(v[i],intersect(dq[bot],dq[bot+1],false))){
            bot++;
        }
        dq[++top]=v[i];
        while(top>bot&&!inPlane(dq[bot],intersect(dq[top],dq[top-1],false))){
            top--;
        }
        while(top>bot&&!inPlane(dq[top],intersect(dq[bot],dq[bot+1],false))){
            bot++;
        }
    }
    top++;
    res.clear();
    if(top-bot<3){
        return;
    }
    for(int i=bot;i<top;i++){
        res.PB(v[i]);
    }
    return;
}
