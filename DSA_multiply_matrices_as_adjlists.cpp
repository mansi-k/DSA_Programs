#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define l 2
#define m 3
#define n 3

struct node {
    int data;
    int row;
    int col;
    node *next;
};

int main() {
    node *a[2];
    node *b[3];
    // int l=2, m=3, n=3;
    int x[l][m] = {{3,2,0},{1,1,2}};
    int y[m][n] = {{2,1,0},{3,3,1},{2,0,1}};
    node *root1=NULL, *root2=NULL, *temp1, *temp2;
    for(int i=0;i<l;i++) {
        for(int j=0;j<m;j++) {
            if(x[i][j]==0)
                continue;
            if(j==0) {
                temp1 = new node;
                root1 = temp1;
            }
            else {
                temp1->next = new node;
                temp1 = temp1->next;
            }
            temp1->data = x[i][j];
            temp1->row = i;
            temp1->col = j;
            temp1->next = NULL;
        }
        a[i] = root1;
        root1 = NULL;
    }
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if(y[i][j]==0)
                continue;
            if(j==0) {
                temp2 = new node;
                root2 = temp2;
            }
            else {
                temp2->next = new node;
                temp2 = temp2->next;
            }
            temp2->data = y[i][j];
            temp2->row = i;
            temp2->col = j;
            temp2->next = NULL;
        }
        b[i] = root2;
        root2 = NULL;
    }
    for(int i=0;i<l;i++) {
        temp1 = a[i];
        while(temp1!=NULL) {
            cout << temp1->data << " ";
            temp1 = temp1->next;
        }
        cout << endl;
    }
    cout << endl;
    for(int i=0;i<m;i++) {
        temp2 = b[i];
        while(temp2!=NULL) {
            cout << temp2->data << " ";
            temp2 = temp2->next;
        }
        cout << endl;
    }
//    ------------------MULTIPLY---------------------
    node *c[l];
    node *root3=NULL, *temp3=NULL;
    temp1=NULL;
    temp2=NULL;
    temp3=NULL;

    for(int i=0;i<l;i++) {
        temp1 = a[i];
        int j = 0;
        temp3=NULL;
        int z[n] = {0};
        while(temp1!=NULL) {
            temp2 = b[j];
            while(temp2!=NULL) {
                z[temp2->col] += temp1->data * temp2->data;
                cout << temp2->col << ":" << z[temp2->col] << "  ";
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
            j++;
        }
        for(int k=0;k<n;k++) {
            if(temp3==NULL) {
                temp3 = new node;
                root3 = temp3;
            }
            else {
                temp3->next = new node;
                temp3 = temp3->next;
            }
            temp3->data = z[k];
            temp3->next = NULL;
        }
        c[i] = root3;
        root3 = NULL;
    }
    cout << endl << endl;
    for(int i=0;i<l;i++) {
        temp3 = c[i];
        while(temp3!=NULL) {
            cout << temp3->data << " ";
            temp3 = temp3->next;
        }
        cout << endl;
    }
    return 0;
}
