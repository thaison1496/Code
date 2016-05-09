/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

var road = parseInt(readline()); // the length of the road before the gap.
var gap = parseInt(readline()); // the length of the gap.
var platform = parseInt(readline()); // the length of the landing platform.
printErr(platform);
var speed = parseInt(readline());

function check(i,j){
	if (gap + road - 1 - i < j){
		var pleft = platform - (j - (gap + road - i));
		printErr(pleft);
		if (pleft >= j*(j-1)/2 + 1)
			return true;
		else
			return false;
	}
	else
		return false;
}
function print_track(i,j){
	//for(var i = 0; i < road; i++)
	//printErr(i,j);
	//printErr(f[13][5],f[8][4],f[4][3],f[1][2]);
	res = [];
	for(var k = 0; k < 10; k++)
		res.push('SLOW');
	res.push('JUMP');
	while (i>0){
		
		if (f[i][j] === 0){
			i -= j;
			res.push('WAIT');
		}
		else if (f[i][j] === 1){
			i -= j;
			j += 1;
			res.push('SLOW');
		}
		else {
			i -= j;
			j -= 1;
			res.push('SPEED');
		}
		printErr(i,j);
	}
	//for(var i = res.length - 1; i >= 0; i--)
		//printErr( res[i]);
	return res;
}

function game_loop(res){
// game loop
	for(var i = res.length - 1; i >= 0; i--)
		print( res[i]);
}


//init dp arr
var f = [];

f.push([]);
for(var j = 0; j <= 100; j++)
	f[0].push(2);
f[0][speed] = -2;

var r = [];

for(var i = 1; i < road; i++){
	f.push([]);
	if (r.length > 0){
		break;
	}
	for(var j = 0; j < 100; j++){ // max speed 
		f[i].push(2);
		if (j < 1 || j > i){
			f[i][j] = 2;
		}
		else if (f[i-j][j] != 2){
			printErr(i,j);
			f[i][j] = 0;
		} 
		else if (j>0 && f[i-j][j-1] != 2){
			printErr(i,j);
			f[i][j] = -1;
		}
		else if (f[i-j][j+1] != 2){
			printErr(i,j);
			f[i][j] = 1;
		}
		if (f[i][j] != 2 && check(i,j)){
			var r = print_track(i,j);
			game_loop(r);
			break;
		}
	} 
		
}

