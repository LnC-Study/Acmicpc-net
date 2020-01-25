package programmers;


class Q12 {
    private int answer = 0;
    
    public int solution(int[] numbers, int target) {
        findWays(0, 0, numbers, target);
        return this.answer;
    }
    
    private void findWays(int current, int index, int[] numbers, int target) {
        if (index == numbers.length) {
            if (current == target)
            	this.answer++;
        }
        
        else {
            findWays(current + numbers[index], index + 1, numbers, target);
            findWays(current - numbers[index], index + 1, numbers, target);
        }
    }
}

