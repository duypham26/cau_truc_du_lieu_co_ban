/*Đề bài:
Viết chương trình quản lý điểm số của sinh viên bằng danh sách liên kết đơn.

Yêu cầu:

Định nghĩa cấu trúc Node gồm:

Mã số sinh viên (int).

Tên sinh viên (string).

Điểm trung bình (float).

Con trỏ next trỏ tới sinh viên tiếp theo.

Viết các hàm:

Thêm sinh viên vào cuối danh sách.

In danh sách sinh viên (mã số, tên, điểm).

Tìm sinh viên có điểm trung bình cao nhất và in thông tin.

Tính điểm trung bình của cả lớp.

Viết hàm main() để:

Nhập danh sách gồm n sinh viên từ bàn phím.

Thực hiện các yêu cầu trên và in kết quả.

Đầu ra mong muốn:

Danh sách sinh viên vừa nhập.

Sinh viên có điểm cao nhất.

Điểm trung bình của cả lớp.*/
#include <iostream>
#include <string>
using namespace std;
struct sinh_vien
{
    int id;
    string ten_sv;
    float diem_tb;
    sinh_vien* next;
};
struct list
{
    sinh_vien *first;
    sinh_vien *last;
    /* data */
};
void create_list(list &list_student)
{
    list_student.first=NULL;
    list_student.last=NULL;
}

sinh_vien *create_note()
{
    sinh_vien *x = new sinh_vien;
    cout<<"nhap id: "; cin>>x->id;cout<<endl;
    cout<<"nhap ten SV: ";cin.ignore();getline(cin,x->ten_sv);cout<<endl;
    cout<<"nhap diem trung binh: "; cin>>x->diem_tb;cout<<endl;
    x->next = NULL;
    return x;
}
void add_first(list &danh_sach_sinh_vien, sinh_vien *x)
{
    if (danh_sach_sinh_vien.first == NULL)
    {
        danh_sach_sinh_vien.first = x;
        danh_sach_sinh_vien.last = x;
    }
    else
    {
        x->next = danh_sach_sinh_vien.first;
        danh_sach_sinh_vien.first = x;
    }

}
void add_last(list &danh_sach_sinh_vien, sinh_vien *x)
{
    if (danh_sach_sinh_vien.first == NULL)
    {
        danh_sach_sinh_vien.first = x;
        danh_sach_sinh_vien.last = x;
    }
    else 
    {
        danh_sach_sinh_vien.last->next = x;
        danh_sach_sinh_vien.last = x;
    }
}
void add_after_node(list &danh_sach_sinh_vien, sinh_vien *add, sinh_vien *q)
{
    if (q!=NULL)
    {
        add->next = q->next;
        q->next = add;
    }
    if (danh_sach_sinh_vien.last == q)
    {
        danh_sach_sinh_vien.last = add;
    }
    else 
    {
        add_first(danh_sach_sinh_vien, add);
    }

}

void duyet_danh_sach(list &danh_sach_lien_ket)
{
    int dem = 0;
    float avg = 0;
    sinh_vien *temp;
    temp = danh_sach_lien_ket.first;
    sinh_vien *max = temp;
    cout<<"danh sach sinh vien: "<<endl;
    while (temp != NULL)
    {

        cout<<"id Sinh Vien: "<<temp->id<<endl;
        cout<<"ten sinh vien: "<<temp->ten_sv<<endl;
        cout<<"diem trung binh: "<<temp->diem_tb<<endl;
        cout<<"________________________"<<endl;
        dem++;
        avg += temp->diem_tb;
        if (temp->diem_tb > max->diem_tb)
        max = temp;
        temp = temp->next;
    }
    cout<<"diem trung binh: "<<avg/dem<<endl;
    cout<<"sinh vien co diem trung binh cao nat la: ten:"<<max->ten_sv<<"; ma sv:"<<max->id<<"; diem trung binh: "<<max->diem_tb<<endl;
}
bool tim_trong_danh_sach(list &danh_sach_lien_ket, sinh_vien *x)
{
    bool flag = false;
    sinh_vien *temp;
    temp = danh_sach_lien_ket.first;
    cout<<"danh sach sinh vien: "<<endl;
    while ((temp != NULL)||(flag = true))
    {
        if (temp->id == x->id)
        {
            flag = true;
        }
    }
    return flag;
    
}

bool delete_node(list &danh_sach_lien_ket,sinh_vien *x)
{
    sinh_vien *p;
    p = danh_sach_lien_ket.first;  
    if (danh_sach_lien_ket.first == x)
    {
        danh_sach_lien_ket.first = x->next;
        delete x; return true;
    }
    while (p!=NULL &&p->next !=x )
    p=p->next;
        
    if (p==NULL)
        {
            return false;
        }
    else{
            p->next = x->next;
            delete x;
            return true;
        }
}

    


int main()
{
    int n;
    list danh_sach;
    cout<<"nhap so sinh vien: ";cin>>n;cout<<endl;
    create_list(danh_sach);
    for (int i =0; i<n; i++)
    {
        sinh_vien *x = create_note();
        add_last(danh_sach,x);
    }
    cout <<"bat dau duyet danh sach: "<<endl;
    cout<<"_________________________"<<endl;
    duyet_danh_sach(danh_sach);
}
/*ứng dụng của danh sách liên kết: 
- lý thuyết:
    + cấu trúc dữ liệu động: quản lý bộ nhớ linh hoạt, ko cần cấp phát kích thước cố định như mảng. thích hợp cho các tình huống số lượng phần tử thay đổi thường xuyên
    + cài đặt các cấu trúc dữ liệu khác: stack(ngăn xếp), queue (hàng đợi), hash table (bảng băm),...
    + cấu trúc nâng cao: ds liên kết vòng/kép
- thực tế: 
    + quản lý bộ nhớ, hệ điều hành
    + ứng dụng văn bản, soạn thảo
    + hệ thống đa phương tiện
    thuật toán và đồ 

*/