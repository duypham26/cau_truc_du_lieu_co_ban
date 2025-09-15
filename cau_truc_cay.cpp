/*Cây nhị phân

Viết chương trình nhập một dãy số nguyên (tối đa 15 phần tử) và lưu trữ dưới dạng cây nhị phân bất kỳ.

.Hiển thị cây dưới dạng duyệt tiền tự (Pre-order), trung tự (In-order), và hậu tự (Post-order).

.Cây nhị phân tìm kiếm (BST)

.Từ dãy số nguyên trên, xây dựng cây nhị phân tìm kiếm.

.Viết hàm tìm kiếm một phần tử trong cây.

.Viết hàm xóa một phần tử trong cây và hiển thị kết quả sau khi xóa.

Cây nhị phân tìm kiếm cân bằng (AVL)

Viết chương trình xây dựng cây AVL từ cùng dãy số nguyên.

Minh họa quá trình quay đơn/trái/phải hoặc quay kép nếu có.

Hiển thị độ cao của cây sau mỗi lần chèn.

Cây B (B-Tree)

Cho một bậc 
𝑚
=
3
m=3. Viết chương trình xây dựng cây B với bậc này từ cùng dãy số nguyên.

Thực hiện thao tác chèn lần lượt từng phần tử và hiển thị cây sau mỗi lần chèn.

Viết hàm tìm kiếm một phần tử trong cây B.*/
#include <iostream>
#include <string>
using namespace std; 
const int LH = -1;
const int EH = 0;
const int RH = 1;
void xuong_dong()
{
    cout<<endl;
}

struct nodetree
{
    char chi_so_can_bang;//belance factor
    int key;
    nodetree *left;
    nodetree *right;
    nodetree *parent;
};
typedef struct nodetree *TREE;
void create(TREE &cay_nhi_phan)
{
    cay_nhi_phan = NULL;
}
nodetree* create_node(int t)
{
    nodetree *x = new nodetree;
    if (x == NULL) {return NULL;}
    x->key = t;
    x->left = x->right = NULL;
    return x;
}
bool them_node(TREE cay_nhi_phan, int t)
{
    if (cay_nhi_phan != NULL)
    {
        if ( t==cay_nhi_phan->key)
        {
            return false;
        }
        if (cay_nhi_phan->key < t)
        {
            return them_node(cay_nhi_phan->right, t);
        }
        else
        {
            return them_node(cay_nhi_phan->left,t);
        }
    }
    cay_nhi_phan = create_node(t);
    return true;

}
/*
6 cach duyet cay nhi phan:
- node left right
- node right left | tien tu
- left node right 
- right node left | trung tu
- right left node
- left right node | hau tu
* nguoc voi chuan duoc quyet dinh dua tren trai va phai duoc duyet truoc
*/
void duyet_NRL(TREE goc)//tien tu
{
    if (goc == NULL)return;
    cout<<goc->key<<" ";
    duyet_NRL(goc->right);
    duyet_NRL(goc->left);
}
void duyet_RNL(TREE goc)//trung tu
{
    if (goc == NULL)return;
    duyet_RNL(goc->right);
    cout<<goc->key<<" ";
    duyet_RNL(goc->left);

}
void duyet_LRN(TREE goc)
{
    if (goc == NULL)return;
    duyet_LRN(goc->left);
    duyet_LRN(goc->right);
    cout<<goc->key<<" ";

}
//tuong tu voi cac thuat toan duyet cay khac

//ham tim kiem phan tu trong cay
bool search(TREE goc, TREE t)
{
    
    if (goc == NULL)return false;
    if (t->key == goc->key)
    {
        return true;
    }
    bool check_right = search(goc->right,t);
    bool check_left = search(goc->left,t); 
    return check_right||check_left;
}

//thay 1 phan tu trong cay
void thay_node(TREE goc, TREE goc_phai_trai_nhat)
{
    if (goc_phai_trai_nhat->left != NULL)
    {
        thay_node(goc,goc_phai_trai_nhat->left);
    }
    else
    {
        goc = goc_phai_trai_nhat;
        goc_phai_trai_nhat = goc_phai_trai_nhat->right;

    }
}
//xoa 1 phan tu trong cay:
void xoa_node(TREE t,int x)
{
    if (t == NULL)cout<<"node khong ton tai"<<endl;
    else{
        if (t->key <x)
        xoa_node(t->right,x);
        else{
            if (t->key>x)
            xoa_node(t->left,x);
            else 
            {
                nodetree *tam = t;
                if (t->left == NULL)t = t->right;
                else{
                    if (t->right==NULL)t = t->left;
                    else
                    {
                        thay_node(t,t->right);
                    }
                }
                delete t;
            }
        }
    }
}
