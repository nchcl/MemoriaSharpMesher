/**************************************************************************/
/*                                                                        */
/*                  Jens                                                  */
/*                                                                        */
/**************************************************************************/
/* Allows to display Jacobian Information of a mesh in .m3d format        */
/* Written by Claudio Lobos (clobos@inf.utfsm.cl) 2015					  */
/* UNIVERSIDAD TECNICA FEDERICO SANTA MARIA								  */
/**************************************************************************/

/*
 <JENS: this program computes the Element Normalized Scaled Jacobian (Jens)>
 
 Copyright (C) <2015>  <Claudio Lobos>
 
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/gpl.txt>
 */

#include "Prism.h"

Prism::Prism(vector<int> &pts):Element(pts){
    type='R';
    jens_constant.assign(6,sqrt(0.75));
}

Prism::~Prism(){
    
}

double Prism::getAspectRatio(vector<Point3D> &points) {
    
    return 0;
    /*double h,max,min;
     Point a1,a2,a3,p1,p2,aux,pro1,pro2;
     
     vector<int> pointindex = element->getPoints();
     
     p1 = points[pointindex[0]].getPoint();
     p2 = points[pointindex[3]].getPoint();
     pro1 = p1;
     pro2 = p2;
     a1 = p1+p2;
     a1/=2;
     p1 = points[pointindex[1]].getPoint();
     p2 = points[pointindex[4]].getPoint();
     a2 = p1+p2;
     pro1 += p1;
     pro2 += p2;
     a2/=2;
     p1 = points[pointindex[2]].getPoint();
     p2 = points[pointindex[5]].getPoint();
     a3 = p1+p2;
     pro1 += p1;
     pro2 += p2;
     a3/=2;
     max = min = (a1 - a2).norm();
     aux = (a1+a2);
     aux/= 2;
     h = (aux - a3).norm();
     if(h > max)
     max = h;
     if(h < min)
     min = h;
     pro1/=3;
     pro2/=3;
     h = (pro1 - pro2).norm();
     if(h > max)
     max = h;
     if(h < min)
     min = h;
     return min / max;*/
}

vector<vector<unsigned int> > Prism::getTetras() {
    
    vector<vector<unsigned int> > tets;
    tets.reserve(6);
    
    vector<unsigned int> t0(4,0);
    t0[0]=points[0];
    t0[1]=points[2];
    t0[2]=points[3];
    t0[3]=points[1];
    tets.push_back(t0);
    
    vector<unsigned int> t1(4,0);
    t1[0]=points[1];
    t1[1]=points[2];
    t1[2]=points[0];
    t1[3]=points[4];
    tets.push_back(t1);
    
    vector<unsigned int> t2(4,0);
    t2[0]=points[2];
    t2[1]=points[0];
    t2[2]=points[1];
    t2[3]=points[5];
    tets.push_back(t2);
    
    vector<unsigned int> t3(4,0);
    t3[0]=points[3];
    t3[1]=points[5];
    t3[2]=points[4];
    t3[3]=points[0];
    tets.push_back(t3);
    
    vector<unsigned int> t4(4,0);
    t4[0]=points[4];
    t4[1]=points[3];
    t4[2]=points[5];
    t4[3]=points[1];
    tets.push_back(t4);
    
    vector<unsigned int> t5(4,0);
    t5[0]=points[5];
    t5[1]=points[4];
    t5[2]=points[3];
    t5[3]=points[2];
    
    tets.push_back(t5);
    
    return tets;
    
}

vector<unsigned int> Prism::getTetra(int index){
    
    vector<unsigned int> t(4,0);
    if(index==0){
        t[0]=points[0];
        t[1]=points[2];
        t[2]=points[3];
        t[3]=points[1];
    }
    else if(index==1){
        t[0]=points[1];
        t[1]=points[2];
        t[2]=points[0];
        t[3]=points[4];
    }
    else if(index==2){
        t[0]=points[2];
        t[1]=points[0];
        t[2]=points[1];
        t[3]=points[5];
    }
    else if(index==3){
        t[0]=points[3];
        t[1]=points[5];
        t[2]=points[4];
        t[3]=points[0];
    }
    else if(index==4){
        t[0]=points[4];
        t[1]=points[3];
        t[2]=points[5];
        t[3]=points[1];
    }
    else if(index==5){
        t[0]=points[5];
        t[1]=points[4];
        t[2]=points[3];
        t[3]=points[2];
    }
    
    return t;
}
