#pragma once

/*���C++�����ͱ�char,signed char,unsigned char,short,unsigned short,int,unsigned int,
long,unsigned long,long long,unsigned long long,float,double,long double,ԭ��ָ���ṩ��
���汾��ÿһ����Ա��ֵ����__true_type����ʾ��Щ�ͱ���Բ�������ٵķ�ʽ���п�����ֵ����*/
namespace mystl
{
	struct __true_type {};
	struct __false_type {};

	template<typename type>
	struct __type_traits
	{
		typedef __true_type this_dummy_member_must_be_first;
		typedef __false_type has_trivial_default_constructor;
		typedef __false_type has_trivial_copy_constructor;
		typedef __false_type has_trivial_assignment_operator;
		typedef __false_type has_trivial_destructor;
		typedef __false_type is_POD_type;
	};

	template<> struct __type_traits<char>
	{
		typedef __true_type has_trivial_default_constructor;
		typedef __true_type has_trivial_copy_constructor;
		typedef __true_type has_trivial_assignment_operator;
		typedef __true_type has_trivial_destructor;
		typedef __true_type is_POD_type;
	};

	template<> struct __type_traits<signed char>
	{
		typedef __true_type has_trivial_default_constructor;
		typedef __true_type has_trivial_copy_constructor;
		typedef __true_type has_trivial_assignment_operator;
		typedef __true_type has_trivial_destructor;
		typedef __true_type is_POD_type;
	};

	template<> struct __type_traits<wchar_t>
	{
		typedef __true_type has_trivial_default_constructor;
		typedef __true_type has_trivial_copy_constructor;
		typedef __true_type has_trivial_assignment_operator;
		typedef __true_type has_trivial_destructor;
		typedef __true_type is_POD_type;
	};

	template<> struct __type_traits<unsigned char>
	{
		typedef __true_type has_trivial_default_constructor;
		typedef __true_type has_trivial_copy_constructor;
		typedef __true_type has_trivial_assignment_operator;
		typedef __true_type has_trivial_destructor;
		typedef __true_type is_POD_type;
	};

	template<> struct __type_traits<short>
	{
		typedef __true_type has_trivial_default_constructor;
		typedef __true_type has_trivial_copy_constructor;
		typedef __true_type has_trivial_assignment_operator;
		typedef __true_type has_trivial_destructor;
		typedef __true_type is_POD_type;
	};

	template<> struct __type_traits<unsigned short>
	{
		typedef __true_type has_trivial_default_constructor;
		typedef __true_type has_trivial_copy_constructor;
		typedef __true_type has_trivial_assignment_operator;
		typedef __true_type has_trivial_destructor;
		typedef __true_type is_POD_type;
	};

	template<> struct __type_traits<int>
	{
		typedef __true_type has_trivial_default_constructor;
		typedef __true_type has_trivial_copy_constructor;
		typedef __true_type has_trivial_assignment_operator;
		typedef __true_type has_trivial_destructor;
		typedef __true_type is_POD_type;
	};

	template<> struct __type_traits<unsigned int>
	{
		typedef __true_type has_trivial_default_constructor;
		typedef __true_type has_trivial_copy_constructor;
		typedef __true_type has_trivial_assignment_operator;
		typedef __true_type has_trivial_destructor;
		typedef __true_type is_POD_type;
	};

	template<> struct __type_traits<long>
	{
		typedef __true_type has_trivial_default_constructor;
		typedef __true_type has_trivial_copy_constructor;
		typedef __true_type has_trivial_assignment_operator;
		typedef __true_type has_trivial_destructor;
		typedef __true_type is_POD_type;
	};

	template<> struct __type_traits<unsigned long>
	{
		typedef __true_type has_trivial_default_constructor;
		typedef __true_type has_trivial_copy_constructor;
		typedef __true_type has_trivial_assignment_operator;
		typedef __true_type has_trivial_destructor;
		typedef __true_type is_POD_type;
	};

	template<> struct __type_traits<long long>
	{
		typedef __true_type has_trivial_default_constructor;
		typedef __true_type has_trivial_copy_constructor;
		typedef __true_type has_trivial_assignment_operator;
		typedef __true_type has_trivial_destructor;
		typedef __true_type is_POD_type;
	};

	template<> struct __type_traits<unsigned long long>
	{
		typedef __true_type has_trivial_default_constructor;
		typedef __true_type has_trivial_copy_constructor;
		typedef __true_type has_trivial_assignment_operator;
		typedef __true_type has_trivial_destructor;
		typedef __true_type is_POD_type;
	};

	template<> struct __type_traits<float>
	{
		typedef __true_type has_trivial_default_constructor;
		typedef __true_type has_trivial_copy_constructor;
		typedef __true_type has_trivial_assignment_operator;
		typedef __true_type has_trivial_destructor;
		typedef __true_type is_POD_type;
	};

	template<> struct __type_traits<double>
	{
		typedef __true_type has_trivial_default_constructor;
		typedef __true_type has_trivial_copy_constructor;
		typedef __true_type has_trivial_assignment_operator;
		typedef __true_type has_trivial_destructor;
		typedef __true_type is_POD_type;
	};

	template<> struct __type_traits<long double>
	{
		typedef __true_type has_trivial_default_constructor;
		typedef __true_type has_trivial_copy_constructor;
		typedef __true_type has_trivial_assignment_operator;
		typedef __true_type has_trivial_destructor;
		typedef __true_type is_POD_type;
	};

	template<typename T>
	struct __type_traits<T*>
	{
		typedef __true_type has_trivial_default_constructor;
		typedef __true_type has_trivial_copy_constructor;
		typedef __true_type has_trivial_assignment_operator;
		typedef __true_type has_trivial_destructor;
		typedef __true_type is_POD_type;
	};

	template<typename type>
	struct is_integral
	{
		typedef __false_type value;
	};

	template<>
	struct is_integral<bool>
	{
		typedef __true_type value;
	};

	template<>
	struct is_integral<char>
	{
		typedef __true_type value;
	};

	template<>
	struct is_integral<char16_t>
	{
		typedef __true_type value;
	};

	template<>
	struct is_integral<char32_t>
	{
		typedef __true_type value;
	};

	template<>
	struct is_integral<wchar_t>
	{
		typedef __true_type value;
	};

	template<>
	struct is_integral<int>
	{
		typedef __true_type value;
	};

	template<>
	struct is_integral<short>
	{
		typedef __true_type value;
	};

	template<>
	struct is_integral<long>
	{
		typedef __true_type value;
	};

	template<>
	struct is_integral<long long>
	{
		typedef __true_type value;
	};
}