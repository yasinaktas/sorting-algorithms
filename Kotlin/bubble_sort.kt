fun bubble_sort(array:MutableList<Int>, size:Int){
	var change:Boolean = true	
	while(change){
		change = false
		for(i in 0 until size - 1){
			if(array[i + 1] < array[i]){
				val temp = array[i]
				array[i] = array[i + 1]
				array[i + 1] = temp
				change = true
			}
		}
	}
}

fun main(){
	val size = 20
	val array = MutableList(size){it + 1}
	array.shuffle()
	println(array.joinToString())
	bubble_sort(array,size)
	println(array.joinToString())
}
