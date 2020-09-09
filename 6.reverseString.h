void reverseString(char* s, int sSize){
	int p1,p2;
	char tmp;
	if(sSize < 1)
		return;
	p1 =0;
	p2 = sSize -1;
	while(p1 < p2){
		tmp = s[p1];
		s[p1] = s[p2];
		s[p2] = tmp;
		p1++;
		p2--;
	}
}
