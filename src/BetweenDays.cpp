/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};

void getDate(struct node *, int *, int *, int *);
int no_of_days_upto_date(int d, int m, int y);
//int checkDates(int, int, int);
int no_of_days(int);
int is_leap(int);
int no_days_in_year(int d, int m, int y);
int between_days(struct node *date1head, struct node *date2head){
	if (date1head == NULL || date1head == NULL)
		return -1;

	int d1, d2, m1, m2, y1, y2,days,n;
	getDate(date1head,&d1,&m1,&y1);
	getDate(date2head, &d2, &m2, &y2);
	//checkDates(d1, m1, y1);
	//checkDates(d2, m2, y2);

	int i;
	int days1=d1;

	if (y1 < y2){
		days1 = no_days_in_year(d1, m1, y1);

		for (i = y1 + 1; i < y2; i++){
			if (is_leap(i)){
				days1 = days1 + 366;
			}
			else days1 = days1 + 365;
		}
		days1 = days1 + no_of_days_upto_date(d2, m2, y2);
		days1 = days1 + no_days_in_year(d2, m2, y2);
	}
	
	else
	{
		if (d2 < d1){
			n = no_of_days(m2, y2);
			d2 = d2 + n;
			m2 = m2 - 1;
		}
		if (m2 < m1){
			m2 = m2 + 12;
			y2 = y2 - 1;
		}

		int d, m, y;
		d = d2 - d1;
		m = m2 - m1;
		y = y2 - y1;
		days1 = (d)+(m * 30) + (y)-1;

	}
	
	


	return days;
}
void getDate(struct node *h, int *d, int *m, int*y){
	int i;
	*d = 0; *m = 0; *y = 0;
	for (i = 0; i <= 1; i++){
		*d = ((*d) * 10) + (h->data);
		h = h->next;
	}
	for (i = 2; i <= 3; i++){
		*m = ((*m) * 10) + (h->data);
		h = h->next;
	}
	for (i = 4; i <= 7; i++){
		*y = ((*y) * 10) + (h->data);
		h = h->next;
	}
}
int no_of_days(int m,int y){
	if (is_leap && (m == 2))
		return 29;
	else if (m == 2)
		return 28;
	else if (m == 1 || m == 3 || m == 5 || m == 6 || m == 7 || m == 8 || m == 10 || m == 12)
		return 31;
	else return 30;
}
int is_leap(int y){
	if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0)){
		return 1;
	}
	return 0;
}
int no_days_in_year(int d, int m, int y){
	int i,days1;
	if (m < 12){
		for (i = m + 1; i <= 12; i++){
			days1 = days1 + no_of_days(i);
		}
	}
	return days1;

}
int no_of_days_upto_date(int d, int m, int y){
	int days=0 ,i;
	for (i = 1; i < m; i++){
		days = days + no_of_days(m, y);
	}
	days = days + d;
	return days;
}