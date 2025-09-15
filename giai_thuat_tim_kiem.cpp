#include <iostream>
#include <string>
using namespace std; 
void doi_cho(int &a,int &b)
{
    int tam = a;
    a = b;
    b = tam;
}

int tim_min(int a[],int beg,int end)
{
    int k = beg;
    int min = a[beg];
    for (int i = beg+1; i < end; i++)
    {
        if (min > a[i])
        {
            k = i;
            min = a[i];
        }
    }
    return k;
}

void doi_cho_truc_tiep(int a[],int n)
{
    int tam =  0;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j<n; j++)
        {
            if (a[i] > a[j])
            {
            tam = a[i];
            a[i] = a[j];
            a[j] = tam;
            }

        }
    }

}

void chon_truc_tiep(int a[], int n)
{
    int k;
    for (int i = 0; i < n; i++)
    {
        int tam;
        k = tim_min(a,i, n);
        if (a[i] != a[k])
        {
            tam = a[i];
            a[i]=a[k];
            a[k] = tam;
        }
        
        
    }
}

void chen_truc_tiep(int a[],int n)
{
    int i = 1;
    while (i < n)
    {
        int x = a[i];
        int pos = i -1;
        while ((pos >= 0)&&(a[pos]>x))
        {
            a[pos+1]= a[pos];
            pos--;
        }
        a[pos++];
        i++;
    }
    

}

void sap_xep_bong_bong(int a[], int n)
{
    for (int i = 0; i<n;i++)
    {
        for (int j = n-1;j>i; j--)
        {
            if (a[j]<a[j-1])
            {
                doi_cho(a[j],a[i]);
            }
        }
    }
}

void sap_xep_nhanh(int a[], int left, int right)
{
    int i,j,x;
    x = a[(left+right)/2];
    i = left;j = right;
    do
    {
        while (a[i]<x){i++;}
        while (a[j]>x){j--;}
        if(i<=j){doi_cho(a[i],a[j]);i++;j--;}
    } while (i<j);
    if(left < j){sap_xep_nhanh(a,left,j);}
    if(right > i){sap_xep_nhanh(a,i,right);}
    
}
/*void sap_xep_nhanh(int a[], int left,int right)
{
    int i,j,x;
    x = a[(left+right)/2]; //nhập vào 3 biến, ở đó có 2 biến trái phải, 1 biến lưu giá trị ở giữa 
    i = left; j = right;//biến trái,biến phải
    do
    {
        while (a[i]<x){i++;}// duyệt mảng, khi a[i] có giá trị nhỏ hơn x thì chạy lên 1
        while (a[j]>x){j--;}//tương tự với bên trên, nhưng là duyệt xuống
        if (i <= j){doi_cho(a[i],a[j]);i++;j--;}//khi duyệt mà gặp cản trở, sẽ đổi chỗ 2 vị trí bị cấn ấy, tức là đỏi chỗ a[i],s[j] với nhau, sau đó cũng tăng 1 và giảm 1 cho i, j
    }
    while(i < j);//điều liện chạy while
    if (left < j) sap_xep_nhanh(a,left,j);//gọi lại hàm(đệ quy), với điểm bắt đầu là trái và kết thúc là j
    if (right>i) sap_xep_nhanh(a,i,right);//gọi lại hàm(đệ quy), với điểm bắt đầu là i và kết thúc là phải

}*/


int main()
{
    int a[] = {12,3,4,22,34,72};
    sap_xep_nhanh(a,0,5);
    for (int i = 0; i < 6 ;i++)
    {
        cout<<a[i]<<' ';
        if (i == 5)
        {cout<<endl;}
    }
}
