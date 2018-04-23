/* 问题描述
 * 输入两个递增排序的列表，合并这两个链表并使得链表中的节点依然是递增排序的。
 */

listnode* merge(listnode *phead1, listnode *phead2){
	if(phead1 == NULL)
		return phead2;
	if(phead2 == NULL)
		return phead1;

	listnode *mergeHead = NULL;

	if(phead1->data<phead2->data){
		mergeHead = phead1;
		mergeHead->next = merge(phead1->next, phead2);
	}
	else if(phead2->data<phead1->data){
		mergeHead = phead2;
		mergeHead->next = merge(phead1, phead2->next);
	}

	return mergeHead;
}
