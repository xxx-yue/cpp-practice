#pragma once
#include<assert.h>
#include<list>
#include<string>
namespace bit
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		vector() = default;
		vector(const vector<T>& v)
		{
			reserve(v.size());
			for (auto it : v)
			{
				push_back(it);
			}
		}
		template <class inputiterator>
		vector(inputiterator first, inputiterator last)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		vector(size_t n, const T& val = T())
		{
			reserve(n);
			for(int i =0;i<n;i++)
			{
				push_back(val);
			}
		}
	/*	vector(size_t n, const T& val = T())
		{
			reserve(n);
			for (int i = 0; i < n, i++)
			{
				push_back(val);
			}
		}*/
		void clear()
		{
			_end = _start;
		}
		void swap(vector<T>& v)
		{
			std::swap(_end, v._end);
			std::swap(_start, v._start);
			std::swap(_end_of_storage, v._end_of_storage);
		}
		//v3 = v1
		/*vector<T>& operator=(const vector<T>&v)
		{
			if (this != &v)
			{
				clear();
				reserve(v.size());
				for (auto &it : v)
				{
					push_back(it);
				}
			}
		return *this;
		}*/
		vector<T>& operator=(vector<T>v)
		{
			swap(v);
			return *this;
		}
		~vector()
		{
			if (_start)
			{
				delete[]_start;
				_end = _start = _end_of_storage = nullptr;
			}
		}
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _end;
		}
		const_iterator begin() const
		{
			return  _start;
		}
		const_iterator end() const
		{
			return  _end;
		}
		bool empty() const 
		{
			return _start == _end;
		}
		size_t size() const
		{
			return _end - _start;
		}
		size_t capacity() const
		{
			return _end_of_storage - _start;
		}
		/*void reserve(int n)
		{
			if (n > capacity())
			{
				int old_size = size();
				iterator tmp = new T[n];
				memcpy(tmp, _start, size() * sizeof(T));
				delete[] _start;
				_start = tmp;
				_end = tmp + old_size;
				_end_of_storage = tmp + n;
			}
		}*/
		void resize(size_t n, T val = T())
		{
			if (n < size())
			{
				_end = _start + n;
			}
			else
			{
				reserve(n);
				while (_end < _start + n)
				{
					*_end = val;
					_end++;
				}
			}
		}
		void push_back(const T& x)
		{
			if (size() == capacity())
			{
				reserve(capacity() == 0 ? 1 : 2 * capacity());
			}
			*_end = x;
			_end++;
		}
		void pop_back()
		{
			assert(!empty());
			_end--;
		}
		iterator insert(iterator pos, const T& x)
		{
			assert(pos >= _start);
			assert(pos <=_end);
			if (pos==_end)
			{
				size_t len = pos - _start;
				push_back(x);
				pos = _start + len;
			}
			else
			{
				size_t len = pos - _start;
				if (size() == capacity())
				{
					reserve(capacity() == 0 ? 4 : 2 * capacity());
				}
				pos = _start + len;
				iterator eend = _end - 1;
				while (eend>=pos)
				{
					*(eend+1) = *eend;
					eend--;
				}
				*pos = x;
				++_end;
			}
			return pos;
		}

		/*iterator insert(iterator pos, const T& x)
		{
			assert(pos <= _end);
			assert(pos >= _start);
			if (_end == _end_of_storage)
			{
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : 2 * capacity());
				pos = _start + len;
			}
			auto it = _end-1;
			while (it >= pos)
			{
				*(it + 1) = *it;
				it--;
			}
			*pos = x;
			_end++;
			return pos;
		}*/
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t old_size = size();
				T* tmp = new T[n];
				for (int i = 0; i < old_size; i++)
				{
					tmp[i] = _start[i];
				}
				delete[]_start;
				_start = tmp;
				_end = _start + old_size;
				_end_of_storage = _start + n;
			}
		}
		T& operator[](size_t i)
		{
			assert(i < size());
			return *(_start + i);
		}
		const T& operator[](size_t i) const
		{
			assert(i < size());
				return _start[i];
		}
		void erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos < _end);
			auto it = pos;
			while (it < _end - 1)
			{
				*it = *(it + 1);
				it++;
			}
			_end--;
		}
	private:
		iterator  _start = nullptr;
		iterator  _end = nullptr;
		iterator  _end_of_storage = nullptr;
	};
}
template<class T>
void print_vector(const bit::vector<T>& v)
{
	auto it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	/*for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;*/
}
template<class container>
void print_container(const container& v)
{
	/*auto it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;*/
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}
