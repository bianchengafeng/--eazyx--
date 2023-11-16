#pragma once
#include <malloc.h>
#include <stdio.h>
#include <graphics.h>
#include <conio.h>

//#include "ѧ����Ϣ����ϵͳ.cpp"

#define NULL nullptr

struct studentNode {
	long long int id;
	char name[17];
	int clas;
	double mathScore;
	double englishScore;
	double dataHierarchyScore;
	double averangeScore;
	double sumScore;
	studentNode* next;
};
typedef studentNode* pStudentNode;

//�������룺
pStudentNode init(pStudentNode L) {//��ʼ��
	L = (pStudentNode )malloc(sizeof(studentNode));
	L->next = NULL;
	return L;
}
studentNode* add(pStudentNode L) {//β����뷵��ָ�������һ������ 
	pStudentNode q = L;
	pStudentNode s = (pStudentNode)malloc(sizeof(studentNode));

	while (q->next != NULL) {
		q = q->next;
	}
	q->next = s;
	s->next = NULL;

	return s;

}
void addStudent(pStudentNode L,long long int id,char name[17],int clas,double mathScore,double englishScore,double dataHierarchyScore,double averangeScore,double sumScore) {
	studentNode* s = add(L);

	s->id = id;
	int i = 0;
	for (i = 0;i < 17;i++) {
		s->name[i] = name[i];
	}
	s->clas = clas;
	s->mathScore = mathScore;
	s->englishScore = englishScore;
	s->dataHierarchyScore = dataHierarchyScore;
	s->averangeScore = averangeScore;
	s->sumScore = sumScore;
}
bool isEmpty(pStudentNode L) {
	if (L->next != NULL) return false;//�ǿ������
	else {
		return true;//�ǿ������ 
	}
}
void destory(pStudentNode& L) {
	pStudentNode p = L->next, pre = L;
	while (p != nullptr) {
		free(pre);
		pre = p;
		p = pre->next;
	}free(pre);
}//�ͷ�����ռ�
void deleteStudent(pStudentNode L,long long int id) {
	pStudentNode q = L;
	pStudentNode prev = q;
	if (q != NULL && q->id == id)
	{
		L = q->next;
		free(q);
		return;
	}
	while (q != NULL && q->id != id) {
		prev = q;
		q = q->next;

	}
	if (q == NULL) return;
	prev->next = q->next;

	free(q);
}

//�����ã�
int exploreSum(pStudentNode L) {//ͳ��ҳ������
	pStudentNode q = L;
	pStudentNode* exp = &q; // exp ��Ϊ ̽����ָ��
	int page = 0, row = 0;//��ʼ�����Ͻ�һ�㣩
	int const_row = 20;//��׼��ҳ��� 20 ��
	while (q->next != NULL) {
		row++;
		q = q->next;
	}
	page = row / const_row;
	if (row % const_row != 0) {
		page += 1;
	}
	return page;
}
int exploreForm_1(pStudentNode L) {//��¼��һҳ��������ҳ
	pStudentNode q = L;
	pStudentNode* exp = &q; // exp ��Ϊ ̽����ָ��
	
	/*
	int page = 0, row = 0;
	row = exploreSum(L);//��ʼ�����Ͻ�һ�㣩
	int const_row = 20;//��׼��ҳ��� 20 ��
	page = row / const_row + 1;
	*/
	int page = 0, row = 0;//��ʼ�����Ͻ�һ�㣩
	int const_row = 20;//��׼��ҳ��� 20 ��
	while (q->next != NULL) {
		row++;
		q = q->next;
	}
	page = row / const_row;
	if (row % const_row != 0) {
		page += 1;
	}
	//return page;
	//printf_s("ppaag0000000000000000000000000000000:%d %d\n",row, page);
	return page;
}
int exploreForm_2(pStudentNode L) {//��¼����ҳ�ж���������
	pStudentNode q = L;
	int row = 0;
	int page = exploreForm_1(q);
	int const_row = 20;//��׼��ҳ��� 20 ��
	while (q->next!= NULL) {
		row++;
		q = q->next;
	}
	//printf_s("ppaageeeeeeeeeeeeeeeeeeeeeeee:%d\n", page);
	row = row % const_row;
	return row;
}

//�����ã�
/*
void addStudentTEXT(pStudentNode L, int i) {
	studentNode* s = add(L);
	printf("������ѧ��ѧ��:");

	s->id = i;


	printf("������ѧ������:");
	scanf_s("%s", s->name, 20);

	printf("������ѧ���༶:");
	s->clas = i;

	printf("������ѧ����ѧ�ɼ�:");
	s->mathScore = i;

	printf("������ѧ��Ӣ��ɼ�:");
	s->englishScore = i;

	printf("������ѧ�����ݽṹ�ɼ�:");
	s->dataHierarchyScore = i;
	s->averangeScore = (s->mathScore + s->englishScore + s->dataHierarchyScore) / 3;
	printf("-----------------------------------\n");

	//printf_s("clas~~%d\n", s->clas);
	//printf_s("math~~%lf\n", s->mathScore);

	printf("����ӵĸ�ѧ����ƽ����:");
	//scanf("%lf", &s->averangeScore);
	printf("%lf\n", s->averangeScore);
	s->sumScore = s->mathScore + s->englishScore + s->dataHierarchyScore;
	printf("����ӵĸ�ѧ�����ܷ�:");
	//scanf("%lf", &s->sumScore);
	printf("%lf\n", s->sumScore);

}
*/

//���幦�ܣ����������ȣ���

//����
void swap(pStudentNode  a, pStudentNode  b) {
	char temp[50];    
	strcpy_s(temp, a->name);
	strcpy_s(a->name, b->name);
	strcpy_s(b->name, temp);
}
void showStu_class(pStudentNode L) {


	pStudentNode endptr = NULL;
	pStudentNode start = L->next;

	pStudentNode ptr = start;
	pStudentNode lptr = NULL;

	int cnt = 0;
	while (ptr->next != endptr) {

		cnt++;
		ptr = ptr->next;

	}
	cnt++;

	ptr = start;
	// �Ŷ��ٸ�����   �ڼ������� 


	int swapped = 0;
	while (cnt--)
	{
		ptr = start;


		while (ptr->next != endptr) {
			if (ptr->clas < ptr->next->clas) {
				int temp = ptr->id; //id 
				ptr->id = ptr->next->id;
				ptr->next->id = temp;
				temp = ptr->clas; //class
				ptr->clas = ptr->next->clas;
				ptr->next->clas = temp;
				swap(ptr, ptr->next); //name
				temp = ptr->mathScore; //math
				ptr->mathScore = ptr->next->mathScore;
				ptr->next->mathScore = temp;
				temp = ptr->englishScore;//english
				ptr->englishScore = ptr->next->englishScore;
				ptr->next->englishScore = temp;
				temp = ptr->dataHierarchyScore; //data
				ptr->dataHierarchyScore = ptr->next->dataHierarchyScore;
				ptr->next->dataHierarchyScore = temp;
				temp = ptr->sumScore;
				ptr->sumScore = ptr->next->sumScore;
				ptr->next->sumScore = temp;
				temp = ptr->averangeScore;
				ptr->averangeScore = ptr->next->averangeScore;
				ptr->next->averangeScore = temp;
				swapped = 1;
			}
			ptr = ptr->next;
		}
		lptr = ptr;


	}


}
void showStu_id(pStudentNode L) {
	pStudentNode endptr = NULL;
	pStudentNode start = L->next;

	pStudentNode ptr = start;
	pStudentNode lptr = NULL;

	int cnt = 0;
	while (ptr->next != endptr) {

		cnt++;
		ptr = ptr->next;

	}
	cnt++;

	ptr = start;
	int swapped = 0;
	system("cls");

	do {
		ptr = start;
		while (ptr->next != endptr) {
			if (ptr->id < ptr->next->id) {
				int temp = ptr->id; //id 
				ptr->id = ptr->next->id;
				ptr->next->id = temp;
				temp = ptr->clas; //class
				ptr->clas = ptr->next->clas;
				ptr->next->clas = temp;
				swap(ptr, ptr->next); //name
				temp = ptr->mathScore; //math
				ptr->mathScore = ptr->next->mathScore;
				ptr->next->mathScore = temp;
				temp = ptr->englishScore;//english
				ptr->englishScore = ptr->next->englishScore;
				ptr->next->englishScore = temp;
				temp = ptr->dataHierarchyScore; //data
				ptr->dataHierarchyScore = ptr->next->dataHierarchyScore;
				ptr->next->dataHierarchyScore = temp;
				temp = ptr->sumScore;
				ptr->sumScore = ptr->next->sumScore;
				ptr->next->sumScore = temp;
				temp = ptr->averangeScore;
				ptr->averangeScore = ptr->next->averangeScore;
				ptr->next->averangeScore = temp;
				swapped = 1;
			}
			ptr = ptr->next;
		}
		lptr = ptr;
		cnt--;
	} while (swapped && cnt);
}
void showStu_name(pStudentNode L) {
	pStudentNode endptr = NULL;
	pStudentNode start = L->next;

	pStudentNode ptr = start;
	pStudentNode lptr = NULL;

	int cnt = 0;
	while (ptr->next != endptr) {

		cnt++;
		ptr = ptr->next;

	}
	cnt++;

	ptr = start;
	int swapped = 0;
	system("cls");
	while (cnt--)
	{


		ptr = start;

		while (ptr->next != endptr) {
			/* ʹ�� strcoll() �����Ƚ������ַ��� */
			if (strcoll(ptr->name, ptr->next->name) < 0) {
				int temp = ptr->id; //id 
				ptr->id = ptr->next->id;
				ptr->next->id = temp;
				temp = ptr->clas; //class
				ptr->clas = ptr->next->clas;
				ptr->next->clas = temp;
				swap(ptr, ptr->next); //name
				temp = ptr->mathScore; //math
				ptr->mathScore = ptr->next->mathScore;
				ptr->next->mathScore = temp;
				temp = ptr->englishScore;//english
				ptr->englishScore = ptr->next->englishScore;
				ptr->next->englishScore = temp;
				temp = ptr->dataHierarchyScore; //data
				ptr->dataHierarchyScore = ptr->next->dataHierarchyScore;
				ptr->next->dataHierarchyScore = temp;
				temp = ptr->sumScore;
				ptr->sumScore = ptr->next->sumScore;
				ptr->next->sumScore = temp;
				temp = ptr->averangeScore;
				ptr->averangeScore = ptr->next->averangeScore;
				ptr->next->averangeScore = temp;   // ����һ�����ڽ��������ڵ����ݵĺ���
				swapped = 1;
			}
			ptr = ptr->next;
		}
		endptr = ptr;
	}
}
void showStu_math(pStudentNode L) {
	pStudentNode endptr = NULL;
	pStudentNode start = L->next;

	pStudentNode ptr = start;
	pStudentNode lptr = NULL;

	int cnt = 0;
	while (ptr->next != endptr) {

		cnt++;
		ptr = ptr->next;

	}
	cnt++;

	ptr = start;
	int swapped = 0;

	while (cnt--)
	{


		ptr = start;

		while (ptr->next != endptr) {
			if (ptr->mathScore < ptr->next->mathScore) {
				int temp = ptr->id; //id 
				ptr->id = ptr->next->id;
				ptr->next->id = temp;
				temp = ptr->clas; //class
				ptr->clas = ptr->next->clas;
				ptr->next->clas = temp;
				swap(ptr, ptr->next); //name
				temp = ptr->mathScore; //math
				ptr->mathScore = ptr->next->mathScore;
				ptr->next->mathScore = temp;
				temp = ptr->englishScore;//english
				ptr->englishScore = ptr->next->englishScore;
				ptr->next->englishScore = temp;
				temp = ptr->dataHierarchyScore; //data
				ptr->dataHierarchyScore = ptr->next->dataHierarchyScore;
				ptr->next->dataHierarchyScore = temp;
				temp = ptr->sumScore;
				ptr->sumScore = ptr->next->sumScore;
				ptr->next->sumScore = temp;
				temp = ptr->averangeScore;
				ptr->averangeScore = ptr->next->averangeScore;
				ptr->next->averangeScore = temp;
				swapped = 1;
			}
			ptr = ptr->next;
		}
		lptr = ptr;


	}

}
void showStu_english(pStudentNode L) {
	pStudentNode endptr = NULL;
	pStudentNode start = L->next;

	pStudentNode ptr = start;
	pStudentNode lptr = NULL;

	int cnt = 0;
	while (ptr->next != endptr) {

		cnt++;
		ptr = ptr->next;

	}
	cnt++;

	ptr = start;
	int swapped = 0;
	while (cnt--)
	{


		ptr = start;
		while (ptr->next != endptr) {
			if (ptr->englishScore < ptr->next->englishScore) {
				int temp = ptr->id; //id 
				ptr->id = ptr->next->id;
				ptr->next->id = temp;
				temp = ptr->clas; //class
				ptr->clas = ptr->next->clas;
				ptr->next->clas = temp;
				swap(ptr, ptr->next); //name
				temp = ptr->mathScore; //math
				ptr->mathScore = ptr->next->mathScore;
				ptr->next->mathScore = temp;
				temp = ptr->englishScore;//english
				ptr->englishScore = ptr->next->englishScore;
				ptr->next->englishScore = temp;
				temp = ptr->dataHierarchyScore; //data
				ptr->dataHierarchyScore = ptr->next->dataHierarchyScore;
				ptr->next->dataHierarchyScore = temp;
				temp = ptr->sumScore;
				ptr->sumScore = ptr->next->sumScore;
				ptr->next->sumScore = temp;
				temp = ptr->averangeScore;
				ptr->averangeScore = ptr->next->averangeScore;
				ptr->next->averangeScore = temp;
				swapped = 1;
			}
			ptr = ptr->next;
		}
		lptr = ptr;

	}
}
void showStu_dataHierarchy(pStudentNode L) {
	pStudentNode endptr = NULL;
	pStudentNode start = L->next;

	pStudentNode ptr = start;
	pStudentNode lptr = NULL;

	int cnt = 0;
	while (ptr->next != endptr) {

		cnt++;
		ptr = ptr->next;

	}
	cnt++;

	ptr = start;
	int swapped = 0;
	while (cnt--)
	{




		ptr = start;
		while (ptr->next != endptr) {
			if (ptr->dataHierarchyScore < ptr->next->dataHierarchyScore) {
				int temp = ptr->id; //id 
				ptr->id = ptr->next->id;
				ptr->next->id = temp;
				temp = ptr->clas; //class
				ptr->clas = ptr->next->clas;
				ptr->next->clas = temp;
				swap(ptr, ptr->next); //name
				temp = ptr->mathScore; //math
				ptr->mathScore = ptr->next->mathScore;
				ptr->next->mathScore = temp;
				temp = ptr->englishScore;//english
				ptr->englishScore = ptr->next->englishScore;
				ptr->next->englishScore = temp;
				temp = ptr->dataHierarchyScore; //data
				ptr->dataHierarchyScore = ptr->next->dataHierarchyScore;
				ptr->next->dataHierarchyScore = temp;
				temp = ptr->sumScore;
				ptr->sumScore = ptr->next->sumScore;
				ptr->next->sumScore = temp;
				temp = ptr->averangeScore;
				ptr->averangeScore = ptr->next->averangeScore;
				ptr->next->averangeScore = temp;
				swapped = 1;
			}
			ptr = ptr->next;
		}
		lptr = ptr;

	}
}
void showStu_averange(pStudentNode L) {
	pStudentNode endptr = NULL;
	pStudentNode start = L->next;

	pStudentNode ptr = start;
	pStudentNode lptr = NULL;

	int cnt = 0;
	while (ptr->next != endptr) {

		cnt++;
		ptr = ptr->next;

	}
	cnt++;

	ptr = start;
	int swapped = 0;
	do
	{

		ptr = start;
		while (ptr->next != endptr) {

			if (ptr->averangeScore < ptr->next->averangeScore) {
				int temp = ptr->id; //id 
				ptr->id = ptr->next->id;
				ptr->next->id = temp;
				temp = ptr->clas; //class
				ptr->clas = ptr->next->clas;
				ptr->next->clas = temp;
				swap(ptr, ptr->next); //name
				temp = ptr->mathScore; //math
				ptr->mathScore = ptr->next->mathScore;
				ptr->next->mathScore = temp;
				temp = ptr->englishScore;//english
				ptr->englishScore = ptr->next->englishScore;
				ptr->next->englishScore = temp;
				temp = ptr->dataHierarchyScore; //data
				ptr->dataHierarchyScore = ptr->next->dataHierarchyScore;
				ptr->next->dataHierarchyScore = temp;
				temp = ptr->sumScore;
				ptr->sumScore = ptr->next->sumScore;
				ptr->next->sumScore = temp;
				temp = ptr->averangeScore;
				ptr->averangeScore = ptr->next->averangeScore;
				ptr->next->averangeScore = temp;
				swapped = 1;
			}
			// else swapped=0;
			 //if(ptr->next->next=endptr) swapped=0;
			ptr = ptr->next;
		}
		lptr = ptr;
		cnt--;
	} while (swapped && cnt);
}
void showStu_sum(pStudentNode L) {
	pStudentNode endptr = NULL;
	pStudentNode start = L->next;

	pStudentNode ptr = start;
	pStudentNode lptr = NULL;

	int cnt = 0;
	while (ptr->next != endptr) {

		cnt++;
		ptr = ptr->next;

	}
	cnt++;

	ptr = start;
	int swapped = 0;
	system("cls");
	while (cnt--)
	{

		ptr = start;
		while (ptr->next != endptr) {
			if (ptr->sumScore < ptr->next->sumScore) {
				int temp = ptr->id; //id 
				ptr->id = ptr->next->id;
				ptr->next->id = temp;
				temp = ptr->clas; //class
				ptr->clas = ptr->next->clas;
				ptr->next->clas = temp;
				swap(ptr, ptr->next); //name
				temp = ptr->mathScore; //math
				ptr->mathScore = ptr->next->mathScore;
				ptr->next->mathScore = temp;
				temp = ptr->englishScore;//english
				ptr->englishScore = ptr->next->englishScore;
				ptr->next->englishScore = temp;
				temp = ptr->dataHierarchyScore; //data
				ptr->dataHierarchyScore = ptr->next->dataHierarchyScore;
				ptr->next->dataHierarchyScore = temp;
				temp = ptr->sumScore;
				ptr->sumScore = ptr->next->sumScore;
				ptr->next->sumScore = temp;
				temp = ptr->averangeScore;
				ptr->averangeScore = ptr->next->averangeScore;
				ptr->next->averangeScore = temp;
				swapped = 1;
			}
			ptr = ptr->next;
		}
		lptr = ptr;

	}

}


//���ң���������
void search_class(pStudentNode object, pStudentNode newLink, int clas) {
	pStudentNode q = object;
	pStudentNode n = newLink;
	while (q->next != NULL) {
		q = q->next;
		if (q->clas == clas) {
			addStudent(n, q->id, q->name, q->clas, q->mathScore, q->englishScore, q->dataHierarchyScore, q->averangeScore, q->sumScore);
		}
	}

}
void search_id(pStudentNode object, pStudentNode newLink,long long int id) {
	pStudentNode q = object;
	pStudentNode n = newLink;
	while (q->next != NULL) {
		q = q->next;
		if (q->id == id) {
			addStudent(n, q->id, q->name, q->clas, q->mathScore, q->englishScore, q->dataHierarchyScore, q->averangeScore, q->sumScore);
		}
	}

}
void search_name(pStudentNode object, pStudentNode newLink, char name[]) {
	pStudentNode q = object;
	pStudentNode n = newLink;
	while (q->next != NULL) {
		q = q->next;
		if (!strcmp(name, q->name)) {
			addStudent(n, q->id, q->name, q->clas, q->mathScore, q->englishScore, q->dataHierarchyScore, q->averangeScore, q->sumScore);
		}
	}
}
void search_averangeScore(pStudentNode object, pStudentNode newLink, double averangeScore) {
	pStudentNode q = object;
	pStudentNode n = newLink;
	while (q->next != NULL) {
		q = q->next;
		if (q->averangeScore == averangeScore) {
			addStudent(n, q->id, q->name, q->clas, q->mathScore, q->englishScore, q->dataHierarchyScore, q->averangeScore, q->sumScore);
		}
	}

}
void search_sumScore(pStudentNode object, pStudentNode newLink, double sumScore) {
	pStudentNode q = object;
	pStudentNode n = newLink;
	while (q->next != NULL) {
		q = q->next;
		if (q->sumScore == sumScore) {
			addStudent(n, q->id, q->name, q->clas, q->mathScore, q->englishScore, q->dataHierarchyScore, q->averangeScore, q->sumScore);
		}
	}

}
void search_mathScore(pStudentNode object, pStudentNode newLink, double mathScore) {
	pStudentNode q = object;
	pStudentNode n = newLink;
	while (q->next != NULL) {
		q = q->next;
		if (q->mathScore == mathScore) {
			addStudent(n, q->id, q->name, q->clas, q->mathScore, q->englishScore, q->dataHierarchyScore, q->averangeScore, q->sumScore);
		}
	}

}
void search_englishScore(pStudentNode object, pStudentNode newLink, double englishScore) {
	pStudentNode q = object;
	pStudentNode n = newLink;
	while (q->next != NULL) {
		q = q->next;
		if (q->englishScore == englishScore) {
			addStudent(n, q->id, q->name, q->clas, q->mathScore, q->englishScore, q->dataHierarchyScore, q->averangeScore, q->sumScore);
		}
	}

}
void search_dataHierarchyScore(pStudentNode object, pStudentNode newLink, double dataHierarchyScore) {
	pStudentNode q = object;
	pStudentNode n = newLink;
	while (q->next != NULL) {
		q = q->next;
		if (q->dataHierarchyScore == dataHierarchyScore) {
			addStudent(n, q->id, q->name, q->clas, q->mathScore, q->englishScore, q->dataHierarchyScore, q->averangeScore, q->sumScore);
		}
	}

}

//�޸ģ�
void revise_class(pStudentNode object, pStudentNode newLink, long long int id,int clas) {
	pStudentNode q = object;
	pStudentNode n = newLink;
	while (q->next != NULL) {
		q = q->next;
		if (q->id == id) {
			q->clas = clas;
			addStudent(n, q->id, q->name, q->clas, q->mathScore, q->englishScore, q->dataHierarchyScore, q->averangeScore, q->sumScore);
		}
	}
}
void revise_name(pStudentNode object, pStudentNode newLink, long long int id, char name[]) {
	pStudentNode q = object;
	pStudentNode n = newLink;
	while (q->next != NULL) {
		q = q->next;
		if (q->id == id) {
			int i = 0;
			for (i = 0;i < 17;i++) {
				q->name[i] = name[i];
			}
			addStudent(n, q->id, q->name, q->clas, q->mathScore, q->englishScore, q->dataHierarchyScore, q->averangeScore, q->sumScore);
		}
	}
}
void revise_mathScore(pStudentNode object, pStudentNode newLink, long long int id, double mathScore) {
	pStudentNode q = object;
	pStudentNode n = newLink;
	while (q->next != NULL) {
		q = q->next;
		if (q->id == id) {
			q->mathScore = mathScore;
			q->sumScore = 1.0 * q->mathScore + q->englishScore + q->dataHierarchyScore;
			q->averangeScore = q->sumScore * 1.0 / 3.0;
			addStudent(n, q->id, q->name, q->clas, q->mathScore, q->englishScore, q->dataHierarchyScore, q->averangeScore, q->sumScore);
		}
	}
}
void revise_englishScore(pStudentNode object, pStudentNode newLink, long long int id, double englishScore) {
	pStudentNode q = object;
	pStudentNode n = newLink;
	while (q->next != NULL) {
		q = q->next;
		if (q->id == id) {
			q->englishScore = englishScore;
			q->sumScore = 1.0 * q->mathScore + q->englishScore + q->dataHierarchyScore;
			q->averangeScore = q->sumScore * 1.0 / 3.0;
			addStudent(n, q->id, q->name, q->clas, q->mathScore, q->englishScore, q->dataHierarchyScore, q->averangeScore, q->sumScore);
		}
	}
}
void revise_dataHierarchyScore(pStudentNode object, pStudentNode newLink, long long int id, double dataHierarchyScore) {
	pStudentNode q = object;
	pStudentNode n = newLink;
	while (q->next != NULL) {
		q = q->next;
		if (q->id == id) {
			q->dataHierarchyScore = dataHierarchyScore;
			q->sumScore = 1.0 * q->mathScore + q->englishScore + q->dataHierarchyScore;
			q->averangeScore = q->sumScore * 1.0 / 3.0;
			addStudent(n, q->id, q->name, q->clas, q->mathScore, q->englishScore, q->dataHierarchyScore, q->averangeScore, q->sumScore);
		}
	}
}