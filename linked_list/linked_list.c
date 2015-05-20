#define LINKED_LIST_C

#include "stdio.h"
#include "stdlib.h"
#include "linked_list.h"


void init_list(LIST_T *p_list_sp, void (*destroy)(void *))
{
	p_list_sp->size = 0;
	p_list_sp->head_sp = NULL;
	p_list_sp->head_sp = p_list_sp->tail_sp;
	p_list_sp->tail_sp = NULL;
	p_list_sp->destroy = destroy;
}

int list_destroy(LIST_T *p_list_sp)
{

	int i;
	void *data = NULL;
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
	LISTELE_T *insert_element_sp;

	insert_element_sp = (LISTELE_T *)malloc(sizeof(LISTELE_T));
	if(insert_element_sp == NULL)
		return -1;

	if(p_element_sp == NULL)
	{
		/* Replace head */
		insert_element_sp->next = p_list_sp->head_sp;
		p_list_sp->head_sp = insert_element_sp;
		insert_element_sp->data = (void *)p_data;
	}
	else if(p_element_sp->next == NULL)
	{
		/* Replace tail */
		insert_element_sp->next = NULL;
		p_list_sp->tail_sp->next = insert_element_sp;
		insert_element_sp->data = (void *)p_data;
	}
	else{
		/* Insert somewhere in middle */
		insert_element_sp->next = p_element_sp->next;
		p_element_sp->next = insert_element_sp;
		insert_element_sp->data = (void *)p_data;
	}

	/* overflow not yet addressed */
	p_list_sp->size++;

	return 0;
}

void list_del_next(LIST_T *p_list_sp, LISTELE_T *p_element_sp, void **p_data)
{

	LISTELE_T *old_element_sp;

	if(p_list_sp->size == 0)
		return;

	if(p_element_sp == NULL)
	{
		/* Remove head ! */
		*p_data = p_list_sp->head_sp->data;
		p_list_sp->head_sp = p_list_sp->head_sp->next;
		old_element_sp = p_list_sp->head_sp;
	}
	else if(p_element_sp->next == p_list_sp->tail_sp)
	{
		/* Remove tail */
		old_element_sp = p_list_sp->tail_sp;
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
		old_element_sp = p_element_sp->next;
		*p_data = p_element_sp->next->data;
		p_element_sp->next = p_element_sp->next->next;
	}

	free(old_element_sp);
	p_list_sp->size--;
}
