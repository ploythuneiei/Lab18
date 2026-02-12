#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect R1, Rect R2){
	double overlapxstart,overlapxend,overlapx;
	double overlapy,overlapystart,overlapyend;
	
	overlapxstart = (R1.x > R2.x ? R1.x : R2.x);
	overlapxend = (R1.x+R1.w < R2.x+R2.w ? R1.x+R1.w : R2.x+R2.w);
	overlapx = overlapxend - overlapxstart;
	if(overlapx <= 0) return 0;

	overlapystart = (R1.y-R1.h > R2.y-R2.h ? R1.y-R1.h : R2.y-R2.h);
	overlapyend = (R1.y < R2.y ? R1.y : R2.y);
	overlapy = overlapyend - overlapystart;
	if(overlapy <= 0) return 0;

	return overlapx * overlapy;
}			
