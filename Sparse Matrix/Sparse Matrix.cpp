#include <bits/stdc++.h>
using namespace std;

const int Maxterm=20;
class SparseMatrix;
class MatrixTerm{
    friend class SparseMatrix;
private:
    int row,col,value;
public:
    MatrixTerm(int a=0,int b=0,int c=0){
        row=a; col=b; value=c;
    }
    friend ostream& operator<<(ostream& os,MatrixTerm& m){
        os<<"["<<m.row<<"]["<<m.col<<"]:"<<m.value;
        return os;
    }
};
class SparseMatrix{
private:
    int Row,Col,Term;
    MatrixTerm matrix[Maxterm];
public:
    SparseMatrix(int a=0,int b=0){
        Row=a; Col=b; Term=0;
        //cout<<"ROW: "<<Row<<endl;
        //cout<<"COL: "<<Col<<endl;
    }
    SparseMatrix transpose(){
        int RowSize[Col];
        int RowStart[Col];
        SparseMatrix b(Col,Row);
        b.Term=Term;
        if(Term>0){
            for(int i=0;i<Col;i++)
                RowSize[i]=0;
            for(int i=0;i<Term;i++)
                RowSize[matrix[i].col]++;
            RowStart[0]=0;
            for(int i=0;i<Col;i++)
                RowStart[i]=RowStart[i-1]+RowSize[i-1];
            for(int i=0;i<Term;i++){
                int j=RowStart[matrix[i].col];
                b.matrix[j].row=matrix[i].col;
                b.matrix[j].col=matrix[i].row;
                b.matrix[j].value=matrix[i].value;
                RowStart[matrix[i].col]++;
            }
        }
        return b;
    }
    friend istream& operator>>(istream& is,SparseMatrix& m){
        int val;
        for(int i=0;i<m.Row;i++){
            for(int j=0;j<m.Col;j++){
                is>>val;
                if(val){
                    m.matrix[m.Term]=MatrixTerm(i,j,val);
                    m.Term++;
                }
            }
        }
        return is;
    }
    friend ostream& operator<<(ostream& os,SparseMatrix& m){
        for(int i=0;i<m.Term;i++){
            os<<"{"<<i<<"}:"<<m.matrix[i]<<endl;
        }
        return os;
    }
};
int main(){
    SparseMatrix matrix(6,6),tmp(6,6);
    cin>>matrix;
    tmp=matrix.transpose();
    cout<<tmp<<endl;
    return 0;
}