#include <iostream>
using namespace std;

struct Point{
    int x;
    int y;
};

bool checkOverlap(Point l1, Point r1, Point l2, Point r2){
    if(l1.x > r2.x || l2.x > r1.x)
        return false;
    
    if(l2.y < r1.y || l1.y < r2.y)
        return false;
    
    return true;
    
}

int main(){
    
    Point l1 = {0, 10}, r1 = {10, 0};
    Point l2 = {5, 5}, r2 = {15, 0};
    if (checkOverlap(l1, r1, l2, r2))
        cout<<"Rectangles Overlap";
    else
        cout<<"Rectangles Don't Overlap";
    
    return 0;
}