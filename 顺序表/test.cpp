#include "SeqList.h"
void test()
{
	SL seq_list; //定义一个结构体变量
	SLInit(&seq_list);
	SLPushBack(&seq_list,10);
	SLPushBack(&seq_list,20);
	SLPushBack(&seq_list,30);
	SLPushBack(&seq_list,40);
	SLPushBack(&seq_list,50);//会扩容

	SLPrint(&seq_list);
	SLPopBack(&seq_list);

	SLPushFront(&seq_list,100);
	SLPrint(&seq_list);

	SLPopFront(&seq_list);
	SLPrint(&seq_list);

	SLInsert(&seq_list, 2, 88);
	SLPrint(&seq_list);

	SLErase(&seq_list, 2);
	SLPrint(&seq_list);

	int ret = SLFind(&seq_list, 10);
	printf("%d ", ret);

	SLDestroy(&seq_list);

}
int main()
{
	test();
	return 0;
}