#include <stdio.h>
#include "linked_list.h"

static LIST_T l_list_1;


int main(void)
{
	int temp=1;
	LISTELE_T *item_1[5];
	void *data;
	LIST_T *list_1 = &l_list_1;

	init_list(list_1);

	list_ins_next(list_1, item_1[0], &temp);
	temp++;
	list_ins_next(list_1, item_1[1], &temp);
	temp++;
	list_ins_next(list_1, item_1[2], &temp);
	temp++;
	list_ins_next(list_1, item_1[3], &temp);
	temp++;
	list_ins_next(list_1, item_1[4], &temp);

	list_del_next(list_1, item_1[0], &data);
	list_del_next(list_1, NULL, &data);

	return 0;
}
