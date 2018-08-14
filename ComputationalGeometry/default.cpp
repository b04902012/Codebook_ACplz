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

struct Point{
    db x,y;
    Point(db a,db b){x=a;y=b;}
    Point(){x=0;y=0;}
    Point operator=(Point p){
        x=p.x;y=p.y;
        return *this;
    }
};
typedef Point point;
struct Segment{
    Point p1, p2;
    Segment(point a, point b){p1=a;p2=b;}
    Segment(){p1=Point(0,0);p2=Point(0,0);}
};
typedef Segment segment;

struct Polygon{
    vector<point>pointList;
    Polygon(vector<point>a){pointList=a;}
    Polygon(

}
typedef Polygon polygon;

const db PI = acos(-1);
const db INF = 1e18;
const db EPS = 1e-8;

point operator+(const point &p1, const point &p2){
    return point(p1.x+p2.x,p1.y+p2.y);
}
point operator-(const point &p1, const point &p2){
    return point(p1.x-p2.x,p1.y-p2.y);
}
point operator*(const point &p, const db &k){
    return point(p.x*k,p.y*k);
}
point operator/(const point &p, const db &k){
    return point(p.x/k,p.y/k);
}
db operator*(const point &p1,const point&p2){
    return  p1.x*p2.x+p1.y*p2.y;
}
db operator^(const point &p1,const point&p2){
    return p1.x*p2.y-p1.y*p2.x;
}
bool operator<(const point&p1, const point&p2){
    if(p1.x<p2.x-EPS)return true;
    if(p1.x>p2.x+EPS)return false;
    if(p1.y<p2.y-EPS)return true;
    return false
}

polygon convexHull(polygon &p){
    
}

int main() {
    return 0;
}
