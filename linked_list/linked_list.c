#define LINKED_LIST_C

#include "stdio.h"
#include "stdlib.h"
#include "linked_list.h"

void init_list(LIST_T *p_list_sp)
{
	p_list_sp->size = 0;
	p_list_sp->head_sp->data = NULL;
	p_list_sp->head_sp->next = p_list_sp->tail_sp;
	p_list_sp->tail_sp = NULL;
}

int list_destroy(LIST_T *p_list_sp)
{

	int i;
	void *data;
	if(p_list_sp->destroy == NULL)
		return -1;

	for(i=0; i<get_list_size(p_list_sp); i++)
	{
		list_del_next(p_list_sp, p_list_sp->head_sp->next, &data);
		p_list_sp->destroy(data);
	}

	return 0;
}

int list_ins_next(LIST_T *p_list_sp, LISTELE_T *p_element_sp, const void *p_data)
{
	LISTELE_T *this_element_sp, *insert_element_sp;

	insert_element_sp = (LISTELE_T *)malloc(sizeof(LISTELE_T));
	if(insert_element_sp == NULL)
		return -1;

	if(p_element_sp == NULL)
	{
		/* Replace head */
		insert_element_sp->next = p_list_sp->head_sp;
		p_list_sp->head_sp = insert_element_sp;
		insert_element_sp->data = p_data;
	}
	else if(p_element_sp->next == NULL)
	{
		/* Replace tail */
		insert_element_sp->next = NULL;
		p_list_sp->tail_sp->next = insert_element_sp;
		insert_element_sp->data = p_data;
	}
	else{
		/* Insert somewhere in middle */
		insert_element_sp->next = p_element_sp->next;
		p_element_sp->next = insert_element_sp;
		insert_element_sp->data = p_data;
	}

	/* overflow not yet addressed */
	p_list_sp->size++;

	return 0;
}

void list_del_next(LIST_T *p_list_sp, LISTELE_T *p_element_sp, void **p_data)
{

	LISTELE_T *old_element_sp = p_element_sp->next;

	if(p_list_sp->size == 0)
		return;

	if(p_element_sp == NULL)
	{
		/* Remove head ! */
		*p_data = p_list_sp->head_sp->data;
		p_list_sp->head_sp = p_list_sp->head_sp->next;
	}
	else if(p_element_sp->next == p_list_sp->tail_sp)
	{
		/* Remove tail */
		*p_data = p_list_sp->tail_sp->data;
		p_element_sp->next = NULL;
		p_list_sp->tail_sp = p_element_sp;
	}
	else if(p_element_sp->next == NULL)
	{
		/* Nothing to remove after tail. Gracefully leave, no error */
		return;
	}
	else
	{
		*p_data = p_element_sp->next->data;
		p_element_sp->next = p_element_sp->next->next;
	}

	free(old_element_sp);
	p_list_sp->size--;
}
