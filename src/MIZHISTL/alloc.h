#pragma once

#if 0
#	include <new>
#	define __THROW_BAD_ALLOC throw std::bad_alloc
#elif !defined(__THROW_BAD_ALLOC)
#	include <iostream>
#	define __THROW_BAD_ALLOC std::cerr << "out of memery" << std::endl;exit(1)
#endif

namespace mystl
{
	//������һ��������
	class __malloc_alloc_template
	{
	private:
		//���º������������ڴ治������(outofmomery)
		using new_handler = void(*)();                         //C++11using�������(using�����Զ���ģ�����typedef����)
		static void *oom_malloc(size_t);
		static void *oom_realloc(void *, size_t);
		static new_handler __malloc_alloc_oom_handler;           //ָ����oom handler

	public:
		static void *alloccate(size_t);
		static void deallocate(void *p);
		static void *reallocate(void *, size_t old_sz, size_t new_sz);
		static new_handler set_malloc_handler(new_handler);      //ָ���Լ���oom handler
	};

	//�����Ƕ���������
    enum {__ALIGN = 8};                                          //С��������ϵ��߽�
    enum {__MAX_BYTES = 128};                                    //С�����������
    enum {__NFREELISTS = __MAX_BYTES / __ALIGN};                 //free_list�ĸ���
    class __default_alloc_template
    {
	private:
		union obj                                       //free_list�Ľڵ㹹��
		{
			union obj *free_list_link;
			char client_data[1];
		};
	private:
		static size_t ROUND_UP(size_t);                  //�����߽�Ϊ8�ı���
		static obj *free_list[__NFREELISTS];    //����16��free_list
		static size_t FREELIST_INDEX(size_t);            //���������С����freelist���
		static void *refill(size_t n);                   //����һ����СΪn�Ķ���
		static char *chunk_alloc(size_t, size_t&);          //���ÿ�������nobjs����СΪsize������

		static char *start_free;                         //�ڴ����ʼλ��
		static char *end_free;                           //�ڴ�ؽ���λ��
		static size_t heap_size;

	public:
		static void *allocate(size_t);
		static void deallocate(void*, size_t);
		static void *reallocate(void*, size_t old_sz, size_t new_sz);
	};
}
