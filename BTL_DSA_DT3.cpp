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
                XL = "xuat sac";
            }else if (GPA > 3.2 && GPA < 3.59){
                XL = "gioi";
            }else if (GPA > 2.5 && GPA < 3.19){
                XL = "kha";
            }else if (GPA > 2.0 && GPA < 2.49){
                XL = "trung binh";
            }else{
                XL = "thi lai";
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
        cout << endl << "Vi tri can them khong hop le!"<< endl;
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

void in_dau(){
    for(int i=0; i<(10+20+18+20+10+6); i++){
        cout << "-";
    }
    cout << endl << "|" << setw(10) << "MSV" << "|" << setw(20) << "Ho va Ten"
    << "|" << setw(18) << "Ngay sinh" << "|" << setw(20) << "Que quan" << "|" << setw(10) << "Diem" << "|" << endl; 
    for(int i=0; i<(10+20+18+20+10+6); i++){
        cout << "-";
    }
    cout << endl;
}

void dong(){
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

void inXl (node *head, string dk){
    std::map<std::string, std::string> rutgon;
    rutgon["XS"] = "xuat sac"; rutgon["G"] = "gioi"; rutgon["K"] = "kha"; rutgon["TL"] = "thi lai"; rutgon["TB"] = "trung binh";
    int dem=0;
    cout<<endl<<"Danh sach sinh vien thuoc loai "<<rutgon[dk]<<endl;
    in_dau();
    while(head != NULL){
        if (head->data.XL == rutgon[dk]){
            in(head->data);
            dem++;
        }
        head = head->next;
    }
    if(dem==0){
        cout<<"|"<<"Khong co sinh vien nao thuoc loai nay "<<setw(44)<<"|"<<endl;
        dong();
    }
}

void inallXL(node *head){
    string dk[]={"XS", "G", "K", "TB", "TL"};
    for (int i=0; i<5; i++){
        inXl(head, dk[i]);
    }
}

void timTT(node *head, string dc){
    int dem=0;
    cout << "Danh sach sinh vien co thong tin "<<dc<< ": "<<endl;
    in_dau();
    while(head != NULL){
        if(head->data.address==dc||head->data.name==dc||head->data.date==dc) {
            in(head->data);
            dem++;
        }
        head = head->next;
    }
    if (dem==0){
        cout<<"|"<<"Khong co sinh vien nao co thong tin nay"<<setw(44)<<"|"<<endl;
        dong();
    }
}

void timdiem(node *head, double d){
    int dem=0;
    cout << "Danh sach sinh vien dat GPA "<<d<< ": "<< endl;
    in_dau();
    while(head != NULL){
        if(head->data.GPA==d) {
            in(head->data);
            dem++;
        }
        head = head->next;
    }
    if (dem==0){
        cout<<"|"<<"Khong co sinh vien dat GPA nay"<<setw(44)<<"|"<<endl;
        dong();
    }
}

int main(){
    node *head = NULL;
    string msv, dk, dc;
    double d;
    node* sinh_vien_tim_duoc;
     
    cout << "Nhap vao so sinh vien: " ;
    int n,choN,XN; cin >> n;
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
        cout << "1.Tim kiem sinh vien" << endl;
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

                cout << endl << "Danh sach sinh vien sau khi them la: " << endl;
                inds(head);
                break;
            
            case 1:
                cout << endl << "Nhap vao ma sinh vien can tim: " ;
                cin.ignore();
                getline(cin, msv);
                sinh_vien_tim_duoc=  tim_kiem_sinh_vien(head, msv);
                if(sinh_vien_tim_duoc != NULL){
                    cout << endl << "Sinh vien can tim la: " << endl;
                    in_dau();
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
                cout<<endl<<" ****************************[1]: Loc theo GPA";
                cout<<endl<<" ****************************[2]: Loc theo thong tin ca nhan";
                cout<<endl<<" ****************************[3]: loc theo xep loai ";
                cout<<endl<<"lua chon cua ban: ";cin>>XN;
                switch (XN){
                    case 1:
                        cout<<"nhap GPA: ";cin>>d;
                        timdiem(head,d);
                        break;
                    case 2:       
                        cout<<"nhap thong tin ban muon loc(ho ten, dia chi): ";cin.ignore();getline(cin, dk);
                        timTT(head,dk);
                        break;
                    case 3:
                        cout<<endl<<" ****************************XS: loc sinh vien xep loai xuat sac ";
                        cout<<endl<<" *****************************G: loc sinh vien xep loai gioi ";
                        cout<<endl<<" *****************************K: loc sinh vien xep loai kha ";
                        cout<<endl<<" ****************************TB: loc sinh vien xep loai trung binh ";
                        cout<<endl<<" ****************************TL: loc sinh vien thi lai ";
                        cout<<endl<<" ***************************ALL: loc tat ca sinh vien theo xep loai";
                        cout<<endl<<"lua chon cua ban: ";cin>>dk;
                    if (dk == "ALL"){
                        inallXL(head);
                    }
                    else if (dk=="XS"||dk=="G"||dk=="K"||dk=="TB"||dk =="TL"){
                        inXl(head,dk);
                    }
                    else{
                        cout<<"dieu kien khong phu hop ";                            
                    }
                    break;
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
