#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
#define fi first
#define se second

double sq(double a){
    return a*a;
}

double dist(pdd a, pdd b){
    return sqrt(sq(a.fi-b.fi)+sq(a.se-b.se));
}

double area_tri(pdd a, pdd b, pdd c){
    return abs((a.fi*b.se+b.fi*c.se+c.fi*a.se)-(a.se*b.fi+b.se*c.fi+c.se*a.fi))/2.0;
}

double area_fan(double l){
    double ang = asin(l/2);
    return ang;
}

pdd intersect(ll r){
    double a = 1.0+1.0/(r*r), b = -(1.0+1.0/r), c = 1;
    double x = (-b-sqrt(sq(b)-a*c))/a;
    return pdd(x,x/r);
}

double area_side(pdd a, pdd b, pdd c){
    double l = dist(a,b);
    return area_fan(l)-area_tri(a,b,c);
}

int main(){
    double L_area = (4-M_PI)/4.0;
    for(double r = 1.0 ; ; r+=1.0){
        auto p = intersect(r);
        double tarea = area_tri(p,{0,0},{1,0}) - area_side(p,pdd(1,0),pdd(1,1));
        if(tarea*1000 < L_area){
            cout << r << endl;
            return 0;
        }
    }
}
