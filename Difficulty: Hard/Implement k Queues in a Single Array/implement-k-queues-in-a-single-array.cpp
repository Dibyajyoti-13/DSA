class kQueues {
	int *arr;
	int *front;
	int *rear;
	int *next;
	int free_pos;
	
	public:
	kQueues(int n, int k) {
		arr = new int[n];
		next = new int[n];
		front = new int[k];
		rear = new int[k];
		
		free_pos = 0;
		
		for (int i = 0; i < k; i++) {
			front[i] = -1;
			rear[i] = -1;
		}
		
		for (int i = 0; i < n; i++) next[i] = i + 1;
		next[n - 1] = -1;
	}
	
	void enqueue(int x, int i) {
		if (isFull()) return;
		
		int ind = free_pos;
		free_pos = next[ind];
		
		arr[ind] = x;
		
		next[ind] = -1;
		
		if (front[i] == -1) {
			front[i] = ind;
			rear[i] = ind;
		}
		else {
			next[rear[i]] = ind;
			rear[i] = ind;
		}
	}
	
	int dequeue(int i) {
		if (isEmpty(i)) return - 1;
		
		int ind = front[i];
		int val = arr[ind];
		
		front[i] = next[ind];
		
		if (front[i] == -1) rear[i] = -1;
		
		next[ind] = free_pos;
		free_pos = ind;
		
		return val;
	}
	
	bool isEmpty(int i) {
		return front[i] == -1;
	}
	
	bool isFull() {
		return free_pos == -1;
	}
};
