class Solution {
   static int findNumbers(int[] nums){
        int ans =0;
        for(int num: nums){
            if(even(num)){
                ans++;
            }
        }
        return ans;
    }

    static boolean even(int num) {
//        String str=  num+"";
//        int length = str.length();
//        if(length%2 == 0){
//            return true;

        int eve = digits2(num) ;
            if (eve % 2 == 0) {
                return true;
            }




        return false;
    }

    static int digits2(int num){
        if(num<0){
            num= num*-1;
        }
        return (int)(Math.log10(num))+1;
    }
}
