#include <stdio.h>

int main()
{
    int i=0,j,num,nums[5];
    
	printf("5~100까지 범위의 5의 배수를 5개 입력하세요.\n");
	//조건에 맞는 5개의 숫자를 얻기까지 몇번 실행될지 모르므로 while반복문 사용
	while(i<5){
	    printf("[%d번째 숫자]?",i+1);
	    scanf("%d",&num);
	    //5로 나누었을때 나머지가 0이면 5의배수
	    //동시에 만족해야 하는 조건이 여러개 이므로 &&연산자 사용
	    if(num%5==0&&num>4&&num<101){
	        //조건에 맞는 수는 배열에 넣어주고 다음 값을 받기위해 i의 값을 증가
	        nums[i]=num;
	        i++;
	    }else{
	        printf("5~100까지 범위의 5의 배수가 아닙니다. 다시 입력해 주세요.\n");
	    }
	}
	/*밑의 반복문 속 조건문이 실행될때마다 구하게되면 
	성능이 떨어지므로 구할 수 있는 것들은 미리 저장*/
	
	//----2번 최대값 구하기----
	//max에 최대값을 저장하기 위해 초기값을 0으로 초기화
	int max = 0;
	//반복회수가 5번인 것을 알고 있기 때문에 for반복문 사용
	for(i=0;i<5;i++)
	    //최대값인 max보다 비교하는 값이 클경우 최대값으로 설정
	    if(max<nums[i])
	        max=nums[i];
	//----3번 합계 구하기----
    int sum = nums[0]+nums[1]+nums[2]+nums[3]+nums[4];	
	//종료를 선택하기 전까지 무한루프를 돌리기위해 while(1) 사용
	while(1){
    	printf("\n\n---------------------------------------------------------\n\n");
    	printf("입력된 수 [%d, %d, %d, %d,%d]",nums[0],nums[1],nums[2],nums[3],nums[4]);
    	printf("\n1. 10의 배수\n2. 최대값\n3. 합계\n4. 종료\n");
    	printf("\n---------------------------------------------------------\n");
    	//1,2,3,4 이외의 숫자일 경우 다시 받기 위해 사용
    	while(1){
    	scanf("%d",&num);
    	if(num>4||num<1)
    	    printf("\n메뉴에 있는 번호가 아닙니다. 다시 입력해 주세요.\n");
    	else
    	    break;
    	}
    	//조건이 여러개이므로 switch case 문 사용
    	//각 case 끝에 조건문을 끝내주는 break; 추가
    	//default는 4 종료이므로 break;가 아닌 return 0 사용
    	switch(num) {
    	    case 1:
    	        j=0;
    	        printf("\n[10의 배수]" );
    	        //----1번 10 배수 출력----
    	        for(i=0;i<5;i++)
            	    if(nums[i]%10==0){
            	        if(j!=0)
            	            printf(", ");
            	        printf("%d",nums[i]);
            	        j++;
                	   }
                break;
            case 2:
    	        printf("\n[최대값] %d",max);
                break;
            case 3:
    	        printf("\n[합계] %d",sum);
                break;    
            default:
                return 0;
        }
	}
}