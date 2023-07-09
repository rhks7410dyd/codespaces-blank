void moving_hor(int num,bool right){
	auto& now = info[num];
	int start = now.c;
	int dis = now.s;
	if(dis == 0){
		return;
	}
	
	if(!right && start - dis > 0){
		start = start - dis;
	}
	else if(right && start + dis <= C){
		start = start + dis;
	}
	else{//한번은 턴을 하는 경우
		if(!right){
			dis -= (start-1);
			start = 1;
			right = true;
		}
		else{
			dis -= (C-start);
			start =C;
			right = false;
		}
		
		while(dis >= C){
			if(!right){
				dis -= (start-1);
				start = 1;
				right = true;
			}
			else{
				dis -= (C-start);
				start = C;
				right = false;
			}
		}
		if(right){
			now.d = 3;
			start = 1+dis;
		}
		else{
			now.d = 4;
			start = C-dis;
		}
	}
	
	now.c = start;
	return;
}