#pragma warning(4:4596)
#include<string>
#include<iostream>
using namespace std;
struct sinhVien
{
	string hoten, MSSV;
	double dtb;
	sinhVien* next;
	sinhVien() {
		hoten = "";
		MSSV = "";
		dtb = 0.0;
		next = NULL;
	}
	sinhVien(string ht, string ms, double diem, sinhVien* ptr = 0) {
		hoten = ht;
		MSSV = ms;
		dtb = diem;
		next = ptr;
	}
};
struct DSSV
{
	sinhVien* head;
	DSSV()
	{
		head = 0;
	}
	bool isEmpty()
	{
		return (head == NULL);
	}
	void DSSV::them_dau(string ht, string ms, double diem) {
		head = new sinhVien(ht, ms, diem, head);
	}
	void DSSV::them_cuoi(string ht, string ms, double diem) {
		if (isEmpty()) {
			head = new sinhVien(ht, ms, diem);
		}
		else
		{
			sinhVien* tmp = head;
			while (tmp->next != NULL) {
				tmp = tmp->next;
			}
			tmp->next = new sinhVien(ht, ms, diem);
		}
	}
	string DSSV::xoa_dau() {
		sinhVien* tmp = head;
		string mssv = tmp->MSSV;
		head = head->next;
		delete tmp;
		return mssv;
	}
	string DSSV::xoa_cuoi() {
		sinhVien* truoc = 0;
		sinhVien* sau = head;
		while (sau->next != NULL)
		{
			truoc = sau;
			sau = sau->next;
		}
		if (truoc == 0) {
			sinhVien* tmp = sau;
			string mssv = sau->MSSV;
			head = NULL;
			delete tmp;
			return mssv;
		}
		else
		{
			sinhVien* tmp = sau;
			string mssv = tmp->MSSV;
			truoc->next = NULL;
			delete tmp;
			return mssv;
		}
	}
	void DSSV::them_sau_mssv(string ht, string ms, double diem, string mssv_can_tim) {
		sinhVien* find = head;
		while (find != NULL && find->MSSV != mssv_can_tim)
		{
			find = find->next;
		}
		// nếu như không tìm được
		if (find == NULL) {
			cout << " Khong tim thay mssv ban can tim !!! " << endl;
			return;
		}
		else
		{
			if (find->next == NULL)
			{
				them_cuoi(ht, ms, diem);
			}
			else
			{
				sinhVien* tmp = new sinhVien(ht, ms, diem);
				tmp->next = find->next;
				find->next = tmp;
			}
		}
	}
	void DSSV::Xuat_DSSV()
	{
		sinhVien* run = head;
		while (run != NULL)
		{
			cout << "========================================================" << endl;
			cout << "Ma so sinh vien : " << run->MSSV << endl;
			cout << "Ho ten sinh vien : " << run->hoten << endl;
			cout << "Diem trung binh cua sinh vien : " << run->dtb << endl;
			cout << "========================================================" << endl;
			run = run->next;
		}
	}
}; 
