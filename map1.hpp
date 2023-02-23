#ifndef MAP_HPP
#define MAP_HPP

#include <functional>
#include <memory>
#include <utility>
#include "node.hpp"


namespace ft {
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
	class map {
	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef std::pair<const Key, T> value_type;
		typedef Compare key_compare;
		typedef Alloc allocator_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef value_type* pointer;
		typedef const value_type* const_pointer;
		typedef std::ptrdiff_t difference_type;
		typedef size_t size_type;
		typedef typename Alloc::template rebind<value_type>::other value_alloc_type;
		typedef typename Alloc::template rebind<node>::other node_alloc_type;
		typedef node<T>* node_pointer;
		typedef const node<T>* const_node_pointer;
		typedef node<T>& node_reference;
		typedef const node<T>& const_node_reference;
		typedef node_iterator<value_type, node_pointer> iterator;
		typedef node_iterator<value_type, const_node_pointer> const_iterator;
		typedef reverse_node_iterator<iterator> std::reverse_iterator;
		typedef reverse_node_iterator<const_iterator> std::const_reverse_iterator;

	private:
		node_pointer _root;
		node_pointer _begin;
		node_pointer _end;
		size_type _size;
		key_compare _comp;
		value_alloc_type _alloc;
		node_alloc_type _node_alloc;

		node_pointer create_node(const value_type& val) {
			node_pointer node = _node_alloc.allocate(1);
			_alloc.construct(&node->data, val);
			node->left = NULL;
			node->right = NULL;
			node->parent = NULL;
			return node;
		}

		void delete_node(node_pointer node) {
			_alloc.destroy(&node->data);
			_node_alloc.deallocate(node, 1);
		}

		void delete_tree(node_pointer node) {
			if (node == NULL)
				return;
			delete_tree(node->left);
			delete_tree(node->right);
			delete_node(node);
		}

		void copy_tree(node_pointer node, node_pointer parent) {
			if (node == NULL)
				return;
			node_pointer new_node = create_node(node->data);
			new_node->parent = parent;
			if (parent == NULL)
				_root = new_node;
			else if (node->data.first < parent->data.first)
				parent->left = new_node;
			else
				parent->right = new_node;
			copy_tree(node->left, new_node);
			copy_tree(node->right, new_node);
		}

		node_pointer find_node(const key_type& key) const {
			node_pointer node = _root;
			while (node != NULL) {
				if (key == node->data.first)
					return node;
				else if (key < node->data.first)
					node = node->left;
				else
					node = node->right;
			}
			return NULL;
		}

		node_pointer find_node(const_iterator it) const {
			node_pointer node = _root;
			while (node != NULL) {
				if (it == node)
					return node;
				else if (it < node)
					node = node->left;
				else
					node = node->right;
			}
			return NULL;
		}

		node_pointer find_node(const_iterator first, const_iterator last) const {
			node_pointer node = _root;
			while (node != NULL) {
				if (first <= node && node < last)
					return node;
				else if (last <= node)
					node = node->left;
				else
					node = node->right;
			}
			return NULL;
		}
};
}

#endif

