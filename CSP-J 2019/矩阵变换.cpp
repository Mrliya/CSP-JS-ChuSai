/*
�����㷨��ͨ���ݹ�ķ�ʽ�Ծ��������䡣
��0��ʼ��ÿ�ΰѵ�ǰ�ľ��󻮷ֳ��ĸ��Ӿ���
�����ݱ仯����ֱ�õ��ĸ�����ĵ�һ��Ԫ�أ��Ӿ�����
�ݹ�ķ�ʽ������䣬ֱ�������ٱ仯��Ҳ����һ��Ԫ�ص�ʱ�����䡣 
*/ 
#include <cstdio>//ͷ�ļ�����,����scanf��printf��Ҫ���ļ� 
using namespace std;//�����ռ� 
int n;
const int max_size=1<<10;//����10λ���൱�ڳ���2��10�η�
int res[max_size][max_size];//����һ����ά���飬 һ������� 
/*
�ݹ麯����x,yΪ���Ͻ����꣬n�׾���Ҳ�;���Ŀ�� 
tΪ����ĵ�һ��Ԫ�� 
*/
void recursive(int x, int y, int n, int t){
	if(n==0){//�жϾ����Ƿ�ֻ��һ��Ԫ���� 
		res[x][y]=t;//���õ�ǰԪ�ص�ֵ 
		return; 
	}
	int step=1<<(n-1);//��10λ(n-1)���൱��1����2��(n-1)�η�,�ֳɵ�ÿ������Ŀ�� 
	//�ֳ��ĸ����� 
	recursive(x,y,n-1,t); //���Ͻ�
	recursive(x,y+step,n-1,t); //���Ͻ� 
	recursive(x+step,y,n-1,t); //���½� 
	recursive(x+step,y+step,n-1,!t); //���½ǣ��Ӿ����һ��Ԫ��Ҫȡ��	 
}
int main(){
	scanf("%d",&n);
	recursive(0,0,n,0);//��ʼ���Ͻ�ÿ��Ԫ��Ϊ0��n���Ӿ���
	int size=1<<n;//����Ŀ�ȣ�2��n�η� 
	for(int i=0; i<size; ++i){//������� 
		for(int j=0; j<size; ++j)
			printf("%d",res[i][j]);
		puts("");//����	
	} 
	return 0;
}
