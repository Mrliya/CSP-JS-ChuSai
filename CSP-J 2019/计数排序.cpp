/*
这是一道排序问题，考的是计数排序，和桶排序的原理有些相似
核心思想是先统计每个数出现的次数用数组记录，然后统计数组从第二个元素开始，
每一个元素都加上前面所有元素之和，得出新的数就是每个元素的排序位置
双关键字排序时，先根据第二个关键字进行排序，数组ord[]索引是排序顺序，
值是原数组的位置。再对第二关键字已经排序好的数组进行第一关键字排序，
保证首先按第一关键字排序，如果第一关键字相同按第二关键字排好的顺序就行。 

其实第一次对第二个关键字进行排序，只是确定如果两个第一个关键字相同时的处理
方案，即如果第一个关键字相同，第二关键字小的排在前面。 
*/ 
#include<iostream>
#include<cstdio>//头文件 
#include<cstring>//用到memset函数 
using namespace std; //命名空间
const int maxn=10000000;
const int maxs=10000;//定义常量
int n;
unsigned a[maxn],b[maxn],res[maxn],ord[maxn];
unsigned cnt[maxs+1];//计数用的数组 
int main(){
	scanf("%d",&n);
	for(int i=0; i<n; ++i)
		scanf("%d%d",&a[i],&b[i]);//输入原始的数据
	memset(cnt,0,sizeof(cnt));//初始化数据为0
	for(int i=0; i<n; ++i)
		++cnt[b[i]]; //先对数组b的元素数字计数 
	for(int i=0; i<maxs; ++i)
		cnt[i+1]+=cnt[i];//第二个开始，后面的等于前面之和
	for(int i=0; i<5; ++i)
		cout << cnt[i] << " ";
	cout << endl;
	for(int i=0; i<n; ++i) 
		ord[--cnt[b[i]]]=i;//ord的索引为排序好的，i为原数组的索引值既位置
		
	for(int i=0; i<5; ++i)
		cout << ord[i] << " ";
	cout << endl;
	
	/*
	a[] = 3 2 3
	b[] = 4 4 3
	ord = 2 1 0 
	*/
	
	memset(cnt,0,sizeof(cnt));//重置计数为0
	for(int i=0; i<n; ++i) 
		++cnt[a[i]]; //先对数组a的元素数字计数
	for(int i=0; i<maxs; ++i)
		cnt[i+1]+=cnt[i];//第二个开始，后面的等于前面之和
	for(int i=n-1; i>=0; --i)//从后往前排序，因为第二关键字已经排好是从小到大的，如果第一个相同，第二个小的排在前 
		res[--cnt[a[ord[i]]]]=ord[i];//i对应的原来的数组索引为ord[i] 
	for(int i=0; i<5; ++i)
		cout << res[i] << " ";
	cout << endl;
	for(int i=0; i<n; ++i) 
		printf("%d %d\n",a[res[i]],b[res[i]]);// res,索个为排序，值为原数组下标 
	return 0;
} 

/*
3
3 4
2 4
3 3
*/ 
