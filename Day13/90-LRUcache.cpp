class Pair
{
public:
	int key, value;

	Pair(int key=-1, int value=-1)
	{
		this->key = key;
		this->value = value;
	}
};

class LRUCache 
{ 
public:
    Pair *cache;
    int capacity, size;
	LRUCache(int capacity) 
    {
        cache = new Pair[capacity];
		this->capacity = capacity;
        this->size = 0;
	}
    void leftShift(int st)
	{
		if(st == size) 
		{
			return;
		}

		for(int i=st; i<size; i++)
		{
			cache[i-1] = cache[i];
		}

		return;
	}
    
	int getIndex(int key)
	{
		for(int i=0; i<size; i++)
		{
			if(cache[i].key == key)
			{
				return i;
			}
		}

		return -1;
	}
	int get(int key) 
    {
		int id = getIndex(key);

		if(id == -1)
		{
			return id;
		}

		Pair page = cache[id];
		leftShift(id + 1);
		cache[size - 1] = page;

		return page.value;
	}
	void put(int key, int value) 
    {
		int id = getIndex(key);

		if(id != -1)
		{
			Pair page = cache[id];
			leftShift(id + 1);
			page.value = value;
			cache[size - 1] = page;
		}
		
		else
		{
			Pair page(key, value);

			if(size < capacity)
			{
				cache[size] = page;
				size++;
			}
			else
			{
				leftShift(1);
				cache[size - 1] = page;
			}
		}
	}
};
