#include <bits/stdc++.h>
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
const db INF=1e18;
const db EPS=1e-8;
const db PI=acos(-1);

bool gt(db a,db b){return a>b+EPS;}
bool lt(db a,db b){return a<b-EPS;}
bool eq(db a,db b){return !gt(a,b)&&!lt(a,b);}

struct Pt {
    db x,y;
    Pt(){}
    Pt(db x,db y):x(x),y(y){}
    db angle(){return atan2(y,x);};
    db norm(){return sqrt(x*x+y*y);}
    Pt rtt(db t){return Pt(x*cos(t)-y*sin(t),x*sin(t)+y*cos(t));}
};
const Pt ERR=Pt(INF,INF);
Pt operator-(Pt a,Pt b){return Pt(a.x-b.x,a.y-b.y);}
Pt operator+(Pt a,Pt b){return Pt(a.x+b.x,a.y+b.y);}
Pt operator*(Pt p,db k){return Pt(p.x*k,p.y*k);}
Pt operator/(Pt p,db k){return Pt(p.x/k,p.y/k);}
db operator*(Pt a,Pt b){return a.x*b.x+a.y*b.y;}
db operator^(Pt a,Pt b){return a.x*b.y-a.y*b.x;}
bool operator==(Pt a,Pt b){return eq(a.x,a.y)&&eq(b.x,b.y);}
bool prl(Pt a,Pt b){return eq(atan2(a.y,a.x),atan2(b.y,b.x));}

struct Sg{
    Pt s,t;
    Sg(){}
    Sg(Pt s,Pt t):s(s),t(t){}
    Sg(double a,double b,double c,double d):s(a, b),t(c,d){}
    Pt vtr(){return t-s;};
    bool on(Pt p,bool range=true){return prl(p-s,p-t)&&!gt((p-s)*(p-t),0);}
};

struct Pg{
    vector<Pt>lst;
    Pg(){}
    Pg(vector<Pt>&lst):lst(lst){lst.PB(lst[0]);}
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
    p.x=Pt(xa,xb)^Pt(ka,kb);
    p.y=Pt(ya,yb)^Pt(ka,kb);
    if(a.on(p)&&b.on(p))return p;
    return ERR;
}
bool cmp(const &Sg a,const &Sg b){
    if(!eq(a.vtr().angle(),b.vtr().angle))return a.vtr().angle()<b.vtr().angle();
    return gt((b.t-a.s)^a,0);
}
void halfPlaneIntersect(vector<Sg>v,vector<sg>&res){
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
    }
    deque<sg>dq;
    int n=v.size();
    for(int i=1;i<n;i++){
        while(inersect
    }
