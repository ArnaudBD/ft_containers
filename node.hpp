#ifndef NODE_HPP
#define NODE_HPP

namespace ft {
	template <class T>
	struct node {
		T data;
		node* left;
		node* right;
		node* parent;

		node() : data(), left(NULL), right(NULL), parent(NULL) { }
		node(const T& data) : data(data), left(NULL), right(NULL), parent(NULL) { }
		node(const node& node) : data(node.data), left(node.left), right(node.right), parent(node.parent) { }
		node& operator=(const node& node) {
			data = node.data;
			left = node.left;
			right = node.right;
			parent = node.parent;
			return *this;
		}
		~node() { }

		void swap(node& node) {
			T tmp = data;
			data = node.data;
			node.data = tmp;
		}
	};

	template <class T = void, class Compare = std::less<T> >
	class node_iterator {
		public:
			typedef node_iterator iterator;
			typedef node_iterator const_iterator;
			typedef std::ptrdiff_t difference_type;
			typedef std::bidirectional_iterator_tag iterator_category;
			typedef node<T>* pointer;
			typedef node<T>& reference;
			typedef node<T> value_type;

		private:
			pointer _node;

		public:
			node_iterator() : _node(NULL) { }
			node_iterator(pointer node) : _node(node) { }
			node_iterator(const node_iterator& it) : _node(it._node) { }
			node_iterator& operator=(const node_iterator& it) {
				_node = it._node;
				return *this;
			}
			~node_iterator() { }

			reference operator*() const { return *_node; }
			pointer operator->() const { return _node; }

			iterator& operator++() {
				if (_node->right != NULL) {
					_node = _node->right;
					while (_node->left != NULL)
						_node = _node->left;
				}
				else {
					pointer parent = _node->parent;
					while (parent != NULL && _node == parent->right) {
						_node = parent;
						parent = parent->parent;
					}
					_node = parent;
				}
				return *this;
			}
			iterator operator++(int) {
				iterator tmp = *this;
				++*this;
				return tmp;
			}
			iterator& operator--() {
				if (_node == NULL) {
					_node = _node->parent;
					while (_node->right != NULL)
						_node = _node->right;
				}
				else if (_node->left != NULL) {
					_node = _node->left;
					while (_node->right != NULL)
						_node = _node->right;
				}
				else {
					pointer parent = _node->parent;
					while (parent != NULL && _node == parent->left) {
						_node = parent;
						parent = parent->parent;
					}
					_node = parent;
				}
				return *this;
			}
			iterator operator--(int) {
				iterator tmp = *this;
				--*this;
				return tmp;
			}

			bool operator==(const iterator& it) const {
				return _node == it._node;
			}
			bool operator!=(const iterator& it) const {
				return _node != it._node;
			}
	};


	}

#endif