#pragma once
#include <iostream>


using namespace std;




template <typename dataType>


class List
{
private:

	size_t size_of_list; //Number of items in the list

	class Element
	{

	public:

		Element* Next, * Previous; //Pointers to the next and previous element.

		dataType member;

		Element(dataType member, Element* Next = NULL, Element* Previous = NULL)
		{
			this->member = member;
			this->Next = Next;
			this->Previous = Previous;
		}
	};




	Element* Head; //Pointer to the beginning
	Element* Tail; //Pointer to the end


public:


	List()  //Constructor for creating an empty list
	{

		Head = Tail = NULL;
		size_of_list = 0;

	};

	List(dataType member) //Constructor for creating a list with an element
	{

		Element* newNode = new Element(member);

		Head = Tail = newNode;

		size_of_list = 1;

	};

	~List() //Destructor
	{

		clear();

	};

	void clear() 
	{ //Deleting all list members

		Element* temp = Head; // Create temporary node

		while (Head != NULL) //Deleting members
		{
			Element* temp = Head->Next;
			delete Head;
			Head = temp;
		}

		Tail = Head = NULL;

		size_of_list = 0;

	};

	size_t get_size()  //Getting the number of items in the list
	{
		return size_of_list;
	}



	void push_back(dataType member) {          //Adding an item to the end of the list

		Element* newNode = new Element(member);


		if (isEmpty()) {                       //If the list is empty

			Head = Tail = newNode;
		}


		else {                                //If the list is not empty

			newNode->Previous = Tail;
			Tail->Next = newNode;
			Tail = newNode;

		}

		size_of_list++;
	};

	void push_front(dataType newMember)                 //Add a new element forward
	{
		Element* temp = new Element(newMember);

		if (Head != NULL)                             //If List is not empty
		{
			temp->Next = Head;
			Head->Previous = temp;
			Head = temp;
			size_of_list++;
		}

		else                                          //If List is empty
		{
			Head = Tail = temp;
			size_of_list++;
		}
	}


	bool isEmpty()    //Checking for emptiness
	{
		if (Head == NULL)
			return true;
		else
			return false;
	}


	void push_back(List& newList)
	{
		Element* temp = newList.Head;

		for (int i = 0; i < (int)newList.get_size(); i++)
		{

			this->push_back(temp->member);
			temp = temp->Next;

		}
	};




	dataType at(size_t elem)                                                 //Getting an element by index
	{

		if (elem < get_size()) // If index is in List range
		{
			Element* temp = Head; // Create temporary node
			for (int i = 0; i < elem; i++) {
				temp = temp->Next;
			}
			return temp->member;
		}

		else {
			throw out_of_range("Out of range");
		}


	}


	void insert(dataType value, size_t elem)                                //Inserting before an element that was previously available by this index
	{

		if (elem > get_size() - 1)
			throw out_of_range("Out of range");

		else
		{
			if ((elem == 0) || (elem = get_size() - 1))                         //Adding to extreme points
			{
				if (elem == 0)
					push_front(value);
				if (elem = get_size() - 1)
					push_back(value);
			}

			else                                                             //Adding to the middle
			{
				Element* temp = Head, * save;

				for (int i = 0; i < elem - 1; i++)
					temp = temp->Next;

				Element* newElement = new Element(value, NULL, NULL);

				newElement->member = value;
				save = temp->Next;
				temp->Next;
				temp->Next = newElement;
				newElement->Next = save;

				size_of_list++;
			}

		}
	}



	friend std::ostream& operator << (std::ostream& out, List& currentList) //Redefining output
	{
		size_t current_size_of_list = currentList.get_size();

		for (size_t i = 0; i < current_size_of_list; i++)
		{
			cout << currentList.at(i) << endl;
		}
		return out;
	}
};

template<typename dataTypeForKey, typename dataTypeForValue>


class MyMap 
{
private:

	class Element 
	{
	public:

		bool color;					    // Black is 0| Red is 1
		dataTypeForKey key;					
		dataTypeForValue value;				
		Element* left—hild;						
		Element* right—hild;					
		Element* parent;					

		Element(dataTypeForKey key, dataTypeForValue value, Element* parent, bool color, Element* left—hild = NULL, Element* right—hild = NULL) 
		{

			this->key = key;
			this->value = value;
			this->parent = parent;
			this->color = color;
			this->left—hild = left—hild;
			this->right—hild = right—hild;

		}
	};

	Element* root;		
	Element* nil;		

	void leftTurn(Element* first) //Making a left turn
	{		
		Element* second = first -> right—hild;
		first -> right—hild = second -> left—hild;

		if (second -> left—hild != nil)
			second -> left—hild->parent = first;

		second -> parent = first -> parent;

		if (first -> parent == NULL)
			this -> root = second;

		else
		{

			if (first == first -> parent -> left—hild)
				first -> parent -> left—hild = second;

			else
				first -> parent -> right—hild = second;
		}

		second -> left—hild = first;
		first -> parent = second;
	}

	void rightTurn(Element* first) //Making a right turn
	{		
		Element* second = first -> left—hild;
		first -> left—hild = second -> right—hild;

		if (second -> right—hild != nil)
			second -> right—hild -> parent = first;

		second -> parent = first -> parent;

		if (first -> parent == NULL)
			this -> root = second;

		else
		{
			if (first == first -> parent->right—hild)
				first -> parent -> right—hild = second;
			else
				first -> parent -> left—hild = second;
		}

		second -> right—hild = first;
		first -> parent = second;
	}

	void outputOfTreeElement(Element* element) //Output of tree's element
	
	{
		if (element != nil) 
		{
			if (element->right—hild != NULL && element->right—hild != nil)
				outputOfTreeElement(element->right—hild);

			if (element->left—hild != NULL && element->left—hild != nil)
				outputOfTreeElement(element->left—hild);
			
			if(element->parent!= NULL) //If the element is not the root
				cout << " Î˛˜: "<< element -> key << "|«Ì‡˜ÂÌËÂ: " << element -> value<< "|÷‚ÂÚ: "<< element -> color<<"|–Ó‰ËÚÂÎ¸: "<< element -> parent -> key << endl;
			else //If the element is the root
				cout << " Î˛˜: " << element->key << "|«Ì‡˜ÂÌËÂ: " << element->value << "|÷‚ÂÚ: " << element->color << "| ÓÂÌ¸" << endl;

		}
	}
	
	
	void getValue(Element* member, List<dataTypeForValue>* value) //Getting the value of an element and adding it to the list
	{
		if (member != nil) 
		{
			getValues(member -> left—hild, value);

			value -> push_back(member -> value);

			getValues(member -> right—hild, value);
		}
	}

	void getKeys(Element* memeber, List<dataTypeForKey>* key) //Getting the element key and adding it to the list
	{
		if (memeber != nil) 
		{
			getKeys(memeber -> left—hild, key);

			key -> push_back(memeber -> key);

			getKeys(memeber -> right—hild, key);
		}
	}
	
public:

	MyMap() //Empty Tree Constructor
	{

		nil = new Element(NULL, NULL, NULL, 0); //Leaves and root are always black
		root = nil;

	};

	~MyMap() //Destructor
	{
		this -> root == nil; 
	};

	void insert(dataTypeForKey key, dataTypeForValue value)
	{
		Element* temp = new Element(key, value, NULL, 1, nil, nil); //Creating a new red element whose descendants are empty leaves

		if (this -> root == nil) //If the tree is empty
		{
			root = temp;
			temp -> color = 0; //Repaint the element in black
			return;
		}

		else //If the tree is empty
		{
			Element* parent = NULL;
			Element* newNode = this -> root;

			while (newNode != nil) //Until we reached the leaves
			{
				parent = newNode;

				if (temp -> key < newNode -> key) //If the key of the element is smaller, then go to the left
				{
					newNode = newNode -> left—hild;
				}

				else //If the key of the element is bigger, then go to the right
				{
					newNode = newNode -> right—hild;
				}
			}

			temp -> parent = parent;

			if (temp -> key < parent -> key) //If the key of the parent is bigger, then the current element becomes its left child
				parent -> left—hild = temp;

			else //If the key of the parent is smaller, then the current element becomes its right child
				parent -> right—hild = temp;
		}
		if (temp -> parent -> parent == NULL)
			return;
	                                            //We are starting to restore the structure of the red-black tree
		Element* grandPerent; 

		while (temp -> parent -> color == 1) //While perent is Red
		
		{
			bool whatPosition = temp -> parent -> parent -> right—hild == temp -> parent;//Initializing a variable

			grandPerent = whatPosition ? (temp -> parent -> parent -> left—hild) : (temp -> parent -> parent -> right—hild);

			if (grandPerent -> color == 1) //If the color is red
			{
				grandPerent -> color = 0;

				temp -> parent -> color = 0;

				temp -> parent -> parent -> color = 1;

				temp = temp -> parent -> parent;
			}

			else 
			{
				if (temp == (whatPosition ? (temp -> parent -> left—hild) : (temp -> parent -> right—hild))) 
				{
					temp = temp -> parent;
					whatPosition ? rightTurn(temp) : leftTurn(temp);
				}
				temp -> parent -> color = 0;

				temp -> parent -> parent -> color = 1;

				whatPosition ? leftTurn(temp->parent->parent) : rightTurn(temp->parent->parent);//Making rigth or left turn
			}

			if (temp == root) 
			{
				break;
			}
		}

		root->color = 0;

	};

	void remove(dataTypeForKey key) 
	{
		Element* nodeToBeDeleted = find(key);//Getting the address of the desired element

		Element* first = NULL;
		Element* second = NULL;

		int originalColor = nodeToBeDeleted->color;

		second = nodeToBeDeleted;
        //Moving the right descendant of the deleted element to its place
		if (nodeToBeDeleted -> left—hild == nil) 
		{
			first = nodeToBeDeleted -> right—hild;

			if (nodeToBeDeleted -> parent == NULL)
				root = nodeToBeDeleted -> right—hild;

			else
			{

				if (nodeToBeDeleted == nodeToBeDeleted -> parent -> left—hild)
					nodeToBeDeleted -> parent -> left—hild = nodeToBeDeleted -> right—hild;

				else
					nodeToBeDeleted -> parent -> right—hild = nodeToBeDeleted -> right—hild;
			}

			nodeToBeDeleted -> right—hild -> parent = nodeToBeDeleted -> parent;
		}
		else
		{
			if (nodeToBeDeleted -> right—hild == nil)
			{
				first = nodeToBeDeleted -> left—hild;

				if (nodeToBeDeleted -> parent == NULL)
					root = nodeToBeDeleted -> left—hild;

				else
				{

					if (nodeToBeDeleted == nodeToBeDeleted -> parent -> left—hild)
						nodeToBeDeleted -> parent -> left—hild = nodeToBeDeleted -> left—hild;

					else
						nodeToBeDeleted -> parent -> right—hild = nodeToBeDeleted -> left—hild;
				}

				nodeToBeDeleted -> left—hild -> parent = nodeToBeDeleted -> parent;
			}

			else
			{
				second = nodeToBeDeleted -> right—hild;

				while (second -> left—hild != nil)
				{
					second = second -> left—hild;
				}

				originalColor = second -> color; //Saving the color
				first = second -> right—hild;

				if (second -> parent == nodeToBeDeleted)
					first -> parent = second;

				else
				{
					if (second -> parent == NULL)
						root = second -> right—hild;

					else
					{
						if (second == second -> parent -> left—hild)
							second -> parent -> left—hild = second -> right—hild;

						else
							second -> parent -> right—hild = second -> right—hild;
					}
					second -> right—hild -> parent = second->parent;

					second -> right—hild = nodeToBeDeleted -> right—hild;
					second -> right—hild -> parent = second;
				}


				if (nodeToBeDeleted -> parent == NULL)
					root = second;

				else
					if (nodeToBeDeleted == nodeToBeDeleted -> parent -> left—hild)
						nodeToBeDeleted -> parent -> left—hild = second;

					else
						nodeToBeDeleted -> parent -> right—hild = second;

				second -> parent = nodeToBeDeleted -> parent;

				second -> left—hild = nodeToBeDeleted -> left—hild;

				second -> left—hild -> parent = second;

				second -> color = nodeToBeDeleted->color;
			}
		}
		
		//We are starting to restore the structure of the red-black tree
		if (originalColor == 0) 
		{
			Element* sibling;

			while (first != root && first -> color == 0) 
			{
				if (first == first -> parent -> left—hild) 
				{
					sibling = first -> parent -> right—hild;

					if (sibling->color == 1) //if color of the sibling is Red
					{
						sibling -> color = 0; //Making color of simbling black

						first -> parent -> color = 1;//Making parent red
						
						leftTurn(first -> parent); //Making left tern 
						
						sibling = first -> parent -> right—hild;
					}

					if (sibling -> left—hild -> color == 0 && sibling -> right—hild -> color == 0) //If the color of both descendants is black
					{
						sibling -> color = 1;
						first = first -> parent;
					}
					else 
					{
						if (sibling -> right—hild -> color == 0) 
						{
							sibling -> left—hild -> color = 0;//Left child becomes black

							sibling -> color = 1;// Changing color to red

							rightTurn(sibling);//Making right tern

							sibling = first -> parent -> right—hild;
						}
						sibling -> color = first->parent->color;//Changing color to the color of its perent

						first -> parent -> color = 0; //Changing perents color to black

						sibling -> right—hild->color = 0;//Changing right child's color to black

						leftTurn(first -> parent);//Making left tern 

						first = root;
					}
				}
				//We repeat the same algorithm, but change the direction of turns to the opposite
				else 
				{
					sibling = first -> parent -> left—hild;

					if (sibling -> color == 1) 
					{
						sibling -> color = 0;

						first -> parent -> color = 1;

						rightTurn(first->parent); //Making right tern

						sibling = first -> parent -> left—hild;
					}

					if (sibling -> right—hild -> color == 0 && sibling -> right—hild -> color == 0) 
					{
						sibling -> color = 1;
						first = first -> parent;
					}

					else 
					{
						if (sibling -> left—hild -> color == 0)
						{
							sibling -> right—hild -> color = 0;

							sibling -> color = 1;

							leftTurn(sibling); //Making left tern 

							sibling = first -> parent -> left—hild;
						}

						sibling -> color = first -> parent -> color;

						first -> parent -> color = 0;

						sibling -> left—hild -> color = 0;

						rightTurn(first->parent);//Making right tern

						first = root;
					}
				}
			}
			first->color = 0;//Changing color to black
		}

	}

	void print() //Tree output
	{
		if (this->root != nil)
			outputOfTreeElement(this->root);
		else
			throw invalid_argument("Map is empty");
	};
	

	List <dataTypeForKey> get_keys()  //Getting the keys of all tree elements
	{
		List<dataTypeForKey>* keys = new List<dataTypeForKey>;

		getKeys(root, keys);

		return *keys;
	}


	List <dataTypeForValue> get_values() //Getting the values of all tree elements
	{
		List<dataTypeForValue>* values = new List<dataTypeForValue>;

		getValues(root, values);

		return *values;
	}

	
	
	Element* find(dataTypeForKey key) 
	{
		Element* searchable = NULL;
		Element* temp = this -> root;

		while (temp != nil) //Until they reached the leaves
		{
			if (temp -> key == key) //If this is the right element
			{
				searchable = temp;
				break;
			}

			if (temp->key > key) //If the key of the current element is bigger than the key you are looking for
				temp = temp -> left—hild;
			
			else //If the key of the current element is smaller than the key you are looking for
				temp = temp -> right—hild;
		}
		
		if (searchable == NULL) 
		{
			throw invalid_argument("This element is not in the tree");
		}
		
		else
		{			
			 //Return the address of the desired item
			return searchable;

		}
				
	}

	int findForValue(dataTypeForKey key)
	{
		Element* searchable = NULL;
		Element* temp = this->root;

		while (temp != nil) //Until they reached the leaves
		{
			if (temp->key == key) //If this is the right element
			{
				searchable = temp;
				break;
			}

			if (temp->key > key) //If the key of the current element is bigger than the key you are looking for
				temp = temp->left—hild;

			else //If the key of the current element is smaller than the key you are looking for
				temp = temp->right—hild;
		}

		if (searchable == NULL)
		{
			throw invalid_argument("This element is not in the tree");
		}

		else
		{
			//Return the value of the desired item
			return searchable -> value;

		}

	}
	
};