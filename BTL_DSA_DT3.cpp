
// Thêm mới sinh viên vào danh sách - Tìm kiếm sinh viên trên danh sách (Nhập mã sinh viên từ bàn phím) - 

#include <bits/stdc++.h>

using namespace std;

class SINHVIEN {
    public:
        string MSV;
        string name;
        string date;
        string address;
        double GPA;
        string XL;

        SINHVIEN(){};
        void nhap(){
            cout << "Nhap vao ma sinh vien: " ;
            getline(cin, MSV);
            cout << "Nhap vao ho va ten sinh vien: " ;
            getline(cin, name);
            cout << "Nhap vao ngay sinh cua sinh vien: " ;
            getline(cin, date); 
            cout << "Nhap vao dia chi cua sinh vien: " ;
            getline(cin, address);
            cout << "Nhap vao ket qua mon hoc cua sinh vien (GPA<4): " ;
            cin >> GPA;
            cin.ignore();
            if (GPA > 3.6){
                XL = "Xuat sac";
            } else if (GPA > 3.2 && GPA < 3.59) {
                XL = "Gioi";
            } else if (GPA > 2.2 && GPA < 3.19) {
                XL = "Kha";
            } else {
                XL = "Trung binh";
            }
        }            

};


struct node {
    SINHVIEN data;
    node *next;
};

node* makeNode(SINHVIEN data){
    node *newNode = new node();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


int size(node *head){
    int cnt = 0;
    while(head != NULL){
        cnt ++;
        head = head->next;
    }
    return cnt;
}



void them_vao_dau_ds(node **head, SINHVIEN data){
    node *newNode = makeNode(data);
    newNode->next = *head;
    *head = newNode;

}

void them_vao_cuoi_ds(node **head, SINHVIEN data){
    node *newNode = makeNode(data);
    if(*head == NULL){
        *head = newNode;
    } else{
        node *tmp = *head;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next= newNode;
    }
}

void them_vao_giua_ds(node **head,  int k,  SINHVIEN data){
    int n = size(*head);
    if(k < 1 || k > n+1){
        cout << "Vi tri can them khong hop le: "<< endl;
        return;
    }
    if(k == 1){
        them_vao_dau_ds(head, data);
        return;
    }
    node *tmp = *head;
    for(int i = 1; i <= k-2; i++){
        tmp = tmp->next;
    }
    node *newNode = makeNode(data);
    newNode->next = tmp->next;
    tmp->next = newNode;

}

node* tim_kiem_sinh_vien(node *head, string msv){
    node* node1 = head;
    while(head != NULL){
        if(node1->data.MSV == msv){
            return node1;
        }
        node1 = node1->next;
    }
    return NULL;
}
void in(SINHVIEN  data){
    cout<< "|" <<  setw(10) << data.MSV
        << "|" << setw(20)  << data.name 
        << "|" << setw(18) << data.date
        << "|" << setw(20) << data.address
        << "|" << setw(10) << fixed << setprecision(1) <<  data.GPA << "|"  << endl;
    for(int i=0; i<(10+20+18+20+10+6); i++){
        cout << "-";
    }
    cout << endl;
}

void inds (node *head){
    for(int i=0; i<(10+20+18+20+10+6); i++){
        cout << "-";
    }
    cout << endl << "|" << setw(10) << "MSV" << "|" << setw(20) << "Ho va Ten"
    << "|" << setw(18) << "Ngay sinh" << "|" << setw(20) << "Que quan" << "|" << setw(10) << "Diem" << "|" << endl; 
    for(int i=0; i<(10+20+18+20+10+6); i++){
        cout << "-";
    }
    cout << endl;
    while(head != NULL){
        in(head->data);
        head = head->next;
    }
}

void xoaSV(node*& head, string MSV) {
    node* temp = head;
    node* prev = NULL;

    if (temp != NULL && temp->data.MSV == MSV) {
        head = temp->next;
        delete temp;
        cout << "Xoa sinh vien co ma " << MSV << " thanh cong." << endl;
        return;
    }

    while (temp != NULL && temp->data.MSV != MSV) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Khong tim thay sinh vien co ma " << MSV << "." << endl;
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Xoa sinh vien co ma " << MSV << " thanh cong." << endl;
}

void suaSV(node* head, string MSV) {
    node* temp = head;
    while (temp != NULL) {
        if (temp->data.MSV == MSV) {
            cout << "Nhap thong tin moi cho sinh vien " << temp->data.MSV << ":" << endl;
            cout << "Nhap ma sinh vien moi: ";
            getline(cin,temp->data.MSV);
            cout << "Nhap ho ten moi: ";
            getline(cin, temp->data.name);
            cout<<"Nhap ngay sinh moi: ";
            getline(cin, temp->data.date);
            cout<<"Nhap dia chi moi: ";
            getline(cin, temp->data.address);
            cout<<"Nhap diem moi: ";
            cin>>temp->data.GPA;
            cin.ignore();
            cout << "Thong tin sinh vien da duoc sua." << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Khong tim thay sinh vien co ma " << MSV << "." << endl;
}


void inXS (node *head){
    int dem=0;
    cout<<endl<<"Danh sach sinh vien xuat sac: "<<endl;
    while(head != NULL){
        if (head->data.XL == "Xuat sac"){
            in(head->data);
            dem++;
        }
        head = head->next;
    }
    if(dem==0){
        cout<<"Khong co sinh vien nao xep loai xuat sac"<<endl;
    }
}

void inG (node *head){
    int dem=0;
    cout<<endl<<"Danh sach sinh vien gioi: "<<endl ;
    while(head != NULL){
        if (head->data.XL == "Gioi"){
            in(head->data);
            dem++;
        }
        head = head->next;
    }
    if(dem==0){ 
        cout<<"Khong co sinh vien nao xep loai gioi"<<endl;
    }
}

void inK (node *head){
    int dem=0;
    cout<<endl<<"Danh sach sinh vien kha: "<<endl ;
    while(head != NULL){
        if (head->data.XL == "Kha"){
            in(head->data);
            dem++;
        }
        head = head->next;
    }
    if(dem==0){
        cout<<"Khong co sinh vien nao xep loai kha"<<endl;
    }
}

void inTB (node *head){
    int dem=0;
    cout<<endl<<"Danh sach sinh vien trung binh: "<<endl ;
    while(head != NULL){
        if (head->data.XL == "Trung binh"){
            in(head->data);
            dem++;
        }
        head = head->next;
    }
    if(dem==0){
        cout<<"Khong co sinh vien nao xep loai trung binh"<<endl;
    }
}

void timDC(node *head, string dc){
    int dem=0;
    cout << "Danh sach sinh vien o dia chi "<<dc<< ": "<< endl;
    while(head != NULL){
        if(head->data.address==dc) {
            in(head->data);
            dem++;
        }
        head = head->next;
    }
    if (dem==0){
        cout<<"Khong co sinh vien nao thuoc dia chi nay"<<endl;
    }
}

void timdiem(node *head, double d){
    int dem=0;
    cout << "Danh sach sinh vien dat GPA "<<d<< ": "<< endl;
    while(head != NULL){
        if(head->data.GPA==d) {
            in(head->data);
            dem++;
        }
        head = head->next;
    }
    if (dem==0){
        cout<<"Khong co sinh vien dat GPA nay"<<endl;
    }
}

int main(){
    node *head = NULL;
    string msv, XN, dc;
    double d;
    node* sinh_vien_tim_duoc;
     
    cout << "Nhap vao so sinh vien: " ;
    int n,choN; cin >> n;
    cin.ignore();
    for(int i=0; i<n; i++){
        SINHVIEN sv;
        cout<< endl << "Nhap vao thong tin sinh vien thu " << i + 1 <<": " << endl;
        sv.nhap();
        them_vao_cuoi_ds(&head, sv);
    } 

    cout << endl << "Danh sach sinh vien: " << endl;
    inds(head);

    while(1){
        cout<<"\nMENU:\n";
        cout << "0.Them sinh vien " << endl;
        cout << "1.tim kiem sinh vien" << endl;
        cout << "2.Sua thong tin sinh vien" << endl;
        cout << "3.Xoa sinh vien"<<endl;
        cout << "4.Loc sinh vien"<<endl;
        cout << "5.Thoat"<<endl;
        cout << "Chon chuc nang: ";
        cin >> choN;

        switch(choN){
            case 0 :
                cout << endl << "Nhap vao so sinh vien can them vao danh sach: " ;
                int m; cin >> m; cin.ignore();
                for(int i=0; i<m; i++){
                    SINHVIEN sv2;
                    cout<< endl << "Nhap vao thong tin sinh vien can them thu " << i + 1 <<": " << endl;
                    sv2.nhap();
                    cout << "Nhap vao vi tri can them trong danh sach: " ;
                    int k; cin >> k; cin.ignore();
                    them_vao_giua_ds(&head, k, sv2);
                }

                cout << endl << "Danh sach sinh vien sau khi them " << m << " sinh vien vao danh sach la: " << endl;
                inds(head);
                break;
            
            case 1:
                cout << endl << "Nhap vao ma sinh vien can tim: " ;
                cin.ignore();
                getline(cin, msv);
                sinh_vien_tim_duoc=  tim_kiem_sinh_vien(head, msv);
                if(sinh_vien_tim_duoc != NULL){
                    cout << endl << "Sinh vien can tim la: " << endl;
                    in(sinh_vien_tim_duoc->data);
                }
                break;

            case 2:
                cout << endl << "Nhap vao ma sinh vien can sua: " ;
                cin.ignore();
                getline(cin, msv);
                suaSV(head,msv);
                cout << endl << "Danh sach sinh vien sau khi sua : "  << endl;
                inds(head);
                break;

            case 3:
                cout << endl << "Nhap vao ma sinh vien can xoa: " ;
                cin.ignore();
                getline(cin, msv);
                xoaSV(head,msv);
                cout << endl << "Danh sach sinh vien sau khi xoa : "  << endl;
                inds(head);
                break;

case 4:
        cout<<endl<<"ban muon loc thong tin nao: ";
        cout<<endl<<" ***************************GPA: Loc theo GPA";
        cout<<endl<<" ****************************DC: Loc theo dia chi";
        cout<<endl<<" ****************************XS: Xuat sac ";
        cout<<endl<<" *****************************G: Gioi ";
        cout<<endl<<" *****************************K: Kha ";
        cout<<endl<<" ****************************TB: TB ";
        cout<<endl<<" ***************************ALL: Tat ca xep loai ";
        cout<<endl<<"lua chon cua ban: ";cin>>XN;
        if(XN == "GPA"){
            cout<<"nhap GPA: ";cin>>d;
            timdiem(head,d);
        }        
        if(XN == "DC"){
            cout<<"nhap ten dia chi: ";cin.ignore();getline(cin, dc);
            timDC(head,dc);
        }
        if (XN == "XS"){
            inXS(head);
        }
        else if (XN == "G"){
            inG(head);
        }
        else if (XN == "K"){
            inK(head);
        }
        else if (XN == "TB"){
            inTB(head);
        }
        else if (XN == "ALL"){
            inXS(head);
            inG(head);
            inK(head);
            inTB(head);
        }
    break;
    case 5:
    	cout << endl << "Danh sach sinh vien cuoi : "  << endl;
        inds(head);
    	cout<<"Cam On va Tam biet!";
    	return 0;
 default:
                cout << "Nhap khong hop le!" << endl;
                break;
        } 
        cout << endl;
    }
}
