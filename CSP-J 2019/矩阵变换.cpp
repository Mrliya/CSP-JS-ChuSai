/*
分治算法，通过递归的方式对矩阵进行填充。
从0开始，每次把当前的矩阵划分成四个子矩阵，
并根据变化规则分别得到四个矩阵的第一个元素，子矩阵用
递归的方式进行填充，直到不能再变化，也就是一个元素的时候才填充。 
*/ 
#include <cstdio>//头文件引用,输入scanf，printf需要此文件 
using namespace std;//命名空间 
int n;
const int max_size=1<<10;//左移10位，相当于乘以2的10次方
int res[max_size][max_size];//定义一个二维数组， 一个大矩阵 
/*
递归函数，x,y为左上角坐标，n阶矩阵，也就矩阵的宽度 
t为矩阵的第一个元素 
*/
void recursive(int x, int y, int n, int t){
	if(n==0){//判断矩阵是否只有一个元素了 
		res[x][y]=t;//设置当前元素的值 
		return; 
	}
	int step=1<<(n-1);//移10位(n-1)，相当于1乘以2的(n-1)次方,分成的每个矩阵的宽度 
	//分成四个矩阵 
	recursive(x,y,n-1,t); //左上角
	recursive(x,y+step,n-1,t); //右上角 
	recursive(x+step,y,n-1,t); //左下角 
	recursive(x+step,y+step,n-1,!t); //右下角，子矩阵第一个元素要取反	 
}
int main(){
	scanf("%d",&n);
	recursive(0,0,n,0);//初始左上角每个元素为0，n阶子矩阵
	int size=1<<n;//矩阵的宽度，2的n次方 
	for(int i=0; i<size; ++i){//输出矩阵 
		for(int j=0; j<size; ++j)
			printf("%d",res[i][j]);
		puts("");//换行	
	} 
	return 0;
}
