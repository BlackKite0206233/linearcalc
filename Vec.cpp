﻿#include "Vec.h"

#ifndef M_PI//有時候我需要切換許多的編譯器來DEBUG
#define M_PI 3.1415926535897932384626
#endif

Vec::Vec(){
	data=new double[3];
	dim=3;
	data[0]=data[1]=data[2]=0.;
}
Vec::Vec(int s):dim(s){
	data=new double[s];
	for(int i=0;i<s;i++)
		data[i]=0;
}
Vec::Vec(double* d,int s):dim(s){
	data=new double[s];
	for(int i=0;i<s;i++)
		data[i]=d[i];
}
Vec::Vec(const Vec& v){//----Asign
	dim=v.dim;
	data=new double[dim];
	for(int i=0;i<dim;i++)
		data[i]=v.data[i];
}
Vec::~Vec(){
	delete[] data;//delete heap裡的
}
////////// ////////// ////////// //////////
Vec Vec::operator+(const Vec& v){//----Addition
	if(dim!=v.dim) throw "+失敗，維度不同!";
	Vec re(dim);
	for(int i=0;i<dim;i++)
		re.data[i]=data[i]+v.data[i];
	return re;
}
Vec Vec::operator-(const Vec& v){//----Subtraction
	if(dim!=v.dim) throw "-失敗，維度不同!";
	Vec re(dim);
	for(int i=0;i<dim;i++)
		re.data[i]=data[i]-v.data[i];
	return re;
}

Vec Vec::operator*(const double c){//----Scalar multiplication
	Vec v(dim);
	for(int i=0;i<dim;i++)
		v.data[i]=c*data[i];
	return v;
}
Vec operator*(const double c,const Vec& v1){//----Scalar multiplication
	Vec v(v1.dim);
	for(int i=0;i<v1.dim;i++)
		v.data[i]=c*v1.data[i];
	return v;
}
Vec Vec::operator/(const double c){//----Scalar division
	if(c==0) throw "不可除以0";
	Vec v(dim);
	for(int i=0;i<dim;i++)
		v.data[i]=data[i]/c;
	return v;
}
bool Vec::operator==(Vec& v){//----Equality
	return isEqual(v);
}
bool Vec::operator!=(Vec& v){//----Not Equality
	return !(isEqual(v));
}
Vec Vec::operator=(const Vec& v){//----Asign
	if(data) delete[] data;
	dim=v.dim;
	data=new double[dim];
	for(int i=0;i<dim;i++)
		data[i]=v.data[i];
	return *this;
}
////////// ////////// ////////// //////////
void Vec::setO(){//----0
	for(int i=0;i<dim;i++)
		data[i]=0;
}
void Vec::setI(){//----1
	for(int i=0;i<dim;i++)
		data[i]=1.;
}
void Vec::setData(double* d,int s){
	if(data) delete[] data;
	dim=s;
	data=new double[dim];
	for(int i=0;i<dim;i++)
		data[i]=d[i];
}
void Vec::setData(double d,int i){
	if(i>=dim||i<0) throw "setData失敗，超出範圍!";
	data[i]=d;
}
double Vec::getData(int i){
	if(i>=dim||i<0) throw "getData失敗，超出範圍!";
	return data[i];
}
int Vec::getDim(){
	return dim;
}
bool Vec::isEqual(const Vec& v){//----Equality
	if(dim!=v.dim) return false;
	for(int i=0;i<dim;i++)
		if(data[i]!=v.data[i])
			return false;
	return true;
}
double Vec::distance(const Vec& v){//----Distance Between Two Vectors
	if(dim!=v.dim) throw "distance失敗，維度不同!";
	double d=0;
	for(int i=0;i<dim;i++)
		d+=pow(data[i]-v.data[i],2);
	return sqrt(d);
}
double Vec::norm(){//----norm,magnitude,length
	double d=0;
	for(int i=0;i<dim;i++)
		d+=pow(data[i],2);
	return sqrt(d);
}
Vec Vec::normal(){//----normal
	Vec v(dim);
	for(int i=0;i<dim;i++)
		v.data[i]=data[i]/norm();
	return v;
}
void Vec::normalize(){//----normalize
	for(int i=0;i<dim;i++)
		data[i]=data[i]/norm();
}
double Vec::dot(const Vec& v){//----Dot Product
	if(dim!=v.dim) throw "dot失敗，維度不同!";
	double d=0;
	for(int i=0;i<dim;i++)
		d+=data[i]*v.data[i];
	return d;
}
double Vec::angle_cos(Vec& v){//----angle between
	if(dim!=v.dim) throw "angle_cos失敗，維度不同!";
	return dot(v)/norm()/v.norm();
}
double Vec::angle_radian(Vec& v){//----angle between
	if(dim!=v.dim) throw "angle_radian失敗，維度不同!";
	return acos(dot(v)/norm()/v.norm());
}
double Vec::angle_degree(Vec& v){//----angle between
	if(dim!=v.dim) throw "angle_degree失敗，維度不同!";
	return acos(dot(v)/norm()/v.norm())*(180/M_PI);
}
double Vec::comp(Vec& v){//----Component
	if(dim!=v.dim) throw "comp失敗，維度不同!";
	return dot(v)/v.norm();
}
Vec Vec::proj(Vec& v){//----Projection
	if(dim!=v.dim) throw "proj失敗，維度不同!";
	Vec re=comp(v)*(v/v.norm());
	return re;
}
double Vec::Area(Vec& v){
	return cross3_norm(v)/2;
}

Vec Vec::cross3(const Vec& v){
	if(dim!=3||v.dim!=3) throw "cross3失敗，維度不是3!";
	Vec re(3);
	re.data[0]=data[1]*v.data[2]-data[2]*v.data[1];
	re.data[1]=-data[0]*v.data[2]+data[2]*v.data[0];
	re.data[2]=data[0]*v.data[1]-data[1]*v.data[0];
	return re;
}
double Vec::cross3_norm(const Vec& v){
	return cross3(v).norm();
}
bool Vec::isParal(Vec& v){
	if(dim!=v.dim) throw "isParal失敗，維度不同!";
	if(angle_cos(v)==1 || angle_cos(v)==-1) return true;
	return false;
}
bool Vec::isOrtho(const Vec& v){//----Orthogonal
	if(dim!=v.dim) throw "isOrtho失敗，維度不同!";
	return dot(v)==0;
}
Vec Vec::planeNormal(Vec& v){
	return cross3(v);
}
std::string Vec::toString(){
	std::ostringstream out;
	for(int i=0;i<dim;++i){
		if(i==0)
			out<<"(";
		if(i!=dim-1)
			out<<data[i]<<", ";
		else
			out<<data[i]<<")";
	}
	return out.str();
}
