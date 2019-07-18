#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <malloc.h>

#define height 100
char* alph[26];

struct heapnode { 
    char data;
    unsigned freq;
    struct heapnode *left, *right; 
}; 


struct heap { 
    unsigned size;  
    unsigned capacity; 
    struct heapnode** array;
}; 

struct heapnode* newNode(char data, unsigned freq){
    struct heapnode* temp = (struct heapnode*)malloc(sizeof(struct heapnode)); 
    temp->left = temp->right = NULL; 
    temp->data = data; 
    temp->freq = freq;
    return temp; 
}

struct heap* createMinHeap(unsigned capacity){
    struct heap* minHeap = (struct heap*)malloc(sizeof(struct heap)); 
    minHeap->size = 0; 
    minHeap->capacity = capacity;
    minHeap->array = (struct heapnode**)malloc(minHeap->capacity * sizeof(struct heapnode*)); 
    return minHeap; 
} 


void heapify(struct heap* minHeap, int idx){
    int min = idx; 
    int left = 2 * idx + 1; 
    int right = 2 * idx + 2;
    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[min]->freq){
		min = left;
	}
	else if(left < minHeap->size && (minHeap->array[left]->freq == minHeap->array[min]->freq ) ){
		if(right<minHeap->size && minHeap->array[right]->freq < minHeap->array[min]->freq){
//			printf("check 1\n");
			min = right;
		}
		else if(right<minHeap->size && minHeap->array[right]->freq > minHeap->array[min]->freq){
//			printf("check 2\n");
			if(minHeap->array[min]->data > minHeap->array[left]->data){
				min = left;
			}
		}
		else if(right<minHeap->size && minHeap->array[right]->freq == minHeap->array[min]->freq){
			if(minHeap->array[min]->data > minHeap->array[left]->data){
				min = left;
			}
			if(minHeap->array[min]->data > minHeap->array[right]->data){
				min = right;
			}
		}
	}
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[min]->freq)
        min = right; 
    else if(right < minHeap->size && (minHeap->array[right]->freq == minHeap->array[min]->freq ) ){
		if(minHeap->array[left]->freq < minHeap->array[min]->freq){
			min = left;
		}
		else if(minHeap->array[left]->freq > minHeap->array[min]->freq){
			if(minHeap->array[min]->data > minHeap->array[right]->data){
				min = right;
			}
		}
		else if(minHeap->array[right]->freq == minHeap->array[min]->freq){
			if(minHeap->array[min]->data > minHeap->array[left]->data){
				min = left;
			}
			if(minHeap->array[min]->data > minHeap->array[right]->data){
				min = right;
			}
		}
	}
    if (min != idx) {
            		struct heapnode* t = (minHeap->array[min]);
    				(minHeap->array[min]) = (minHeap->array[idx]); 
    				(minHeap->array[idx]) = t; 
					heapify(minHeap, min); 
    } 
}


struct heapnode* extractMin(struct heap* minHeap){ 
    struct heapnode* temp = minHeap->array[0]; 
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size; 
    heapify(minHeap, 0);
    return temp; 
}


void insertheap(struct heap* minHeap, struct heapnode* minHeapNode){
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq){ 
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode; 
}


void buildMinHeap(struct heap* minHeap){
    int n = minHeap->size - 1;
    int i;
    
    for (i = (n - 1) / 2; i >= 0; --i) {	
		heapify(minHeap, i);
	}
}



struct heap* buildheap(char data[], int freq[], int size){ 
    struct heap* minHeap = createMinHeap(size);

    int i=0;
    for (i = 0; i < size; ++i) 
        minHeap->array[i] = newNode(data[i], freq[i]);
    minHeap->size = size; 

    buildMinHeap(minHeap);

    return minHeap; 
}


struct heapnode* buildtree(char data[], int freq[], int size){
    struct heapnode *left, *right, *top;

    struct heap* minHeap = buildheap(data, freq, size);
    while (minHeap->size!=1) {
        left = extractMin(minHeap); 
        right = extractMin(minHeap);

        top = newNode('$', left->freq + right->freq);
        top->left = left; 
        top->right = right;
        insertheap(minHeap, top);
    } 
 
    return extractMin(minHeap);
}


void printCodes(struct heapnode* root, int arr[], int top){  
    
	int i;
	if (root->left){ 
        arr[top] = 0; 
        printCodes(root->left, arr, top + 1);
    }
    if (root->right){ 
        arr[top] = 1; 
        printCodes(root->right, arr, top + 1); 
    }
    if (!root->left&&!root->right){
        int x = root->data - 'a';
		alph[x] = (char*)malloc((top+1)*(sizeof(char)));
   		 for (i = 0; i < top; i++) 
        	*(alph[x]+i) = arr[i] + '0';
    		*(alph[x]+top) = '\0';
					}
    } 
 


void HuffmanCodes(char data[], int freq[], int size){  
    struct heapnode* root = buildtree(data, freq, size);

    int arr[height], top = 0;

    printCodes(root, arr, top);
}




void freq_arr(char input[], char arr[], int freq[], int inputsize, int* size )

{ 
	int i = 0,j=0,k=0,location=-1;

	while(i<inputsize){
						k = 0;
						while(k<i){
								if(input[i]== input[k])
								{
									location=k;
									break;
								}
									k++;
									
									location=-1;
								}
						
		if( location == -1){
			arr[j] = input[i];
			freq[j]++;
			(*size)++;
			j++;
		}
		else{
			freq[location]++;
		}
		i++;
	}

	for(j=0;j<*size;j++)
		printf("%c",arr[j]);
	return;
}


void print(char input[], int size, FILE* out){

	int i = 0;
	int s; 
	int idx; 
	while(i<size-1){
		idx = input[i]-'a';
		fprintf(out, "%s ", alph[idx]);
		i++;
	}
	fprintf(out, "\n");
}


int main(){ 
	FILE * in, *out;
	out=fopen("output.txt","w");
	char input[50];
	char ch1;
	int size;
	if((in=fopen("input.txt","r"))!=NULL){
	
		while(fgets(input,49,in)!=NULL)
		{

			int inputsize=strlen(input);
			printf("%d",inputsize);
			input[inputsize-1]='\0';
			inputsize--;
			char arr[100]={'0'};
			int freq[100]={0};
			size=0;

			freq_arr(input,arr,freq,inputsize,&size);
    		HuffmanCodes(arr,freq,size);
    		print(input,inputsize+1,out);
    		fscanf(in,"\n");
		}
	}
	else{
		printf("\nFILE doesn't exist");
		exit(0);
	}
    return 0;
}
