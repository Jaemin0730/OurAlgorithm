// 반복문 이용
   int iterativePower(int x, int n)
   {
      int ret = 1;
      for (int i = 0; i < n; i++)
      {
         ret = ret * x;
      }
      return ret;
   }
   
// 재귀함수 이용
   int resursivePower(int x, int n)
   {
       if (n == 0) return 1;  // base case
       if (n == 1) return x;  // base case
   
       return x * resursivePower(x, n - 1);
   }    

// 분할정복 기반
   
   int dcPower(int x, int n)
   {
      if (n == 0) return 1;
      if (n == 1) return x;
   
      if (n % 2 == 0)  // 짝수일 때
      {
         int ret = dcPower(x, n / 2);
         return ret * ret;
      }
       else  // 홀수일 때
      {
         int ret = dcPower(x, (n - 1) / 2);
          return ret * ret;
      }
   }