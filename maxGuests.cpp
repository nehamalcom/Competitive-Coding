class Solution{

	public:
	vector<int> findMaxGuests(int Entry[], int Exit[], int N)
	{
	   sort(Entry, Entry+N);
	   sort(Exit, Exit+N);

	   int currGuests = 0, maxGuests = -1, timeMax = 0;
	   //mergesort both arrays
	   int i=0, j=0;
	   while (i<N && j<N) {
	       if(Entry[i]<=Exit[j]) {
	           currGuests++;
	           if(currGuests>maxGuests) {
	               maxGuests = currGuests;
	               timeMax = Entry[i];
	           }
	           i++;
	       }
	       else {
	           currGuests--;
	           j++;
	       }
	   }
	   return {maxGuests, timeMax};
 }
	   /*
	   int max_time = INT_MIN;
	   for(int i=0;i<N;i++){
	       if (Exit[i]>max_time)
	            max_time = Exit[i];
	   }
	   vector<int> guest_count(max_time+1);
	   for(int i=0; i<N;i++) {
	       for(int k=Entry[i]; k<=Exit[i];k++)
	            guest_count[k]++;
	   }
	   int max_guests = -1, time_of_max_guests;
	   for(int i=1;i<max_time+1;i++){
	       //cout<< "at "<<i<<" there were "<<guest_count[i]<<endl;
	       //cout<< endl<<"max_guests = "<<max_guests;
	       if (guest_count[i]>max_guests){
	           max_guests = guest_count[i];
	           time_of_max_guests=i;
	       }
	   }
	   return {max_guests,time_of_max_guests};
	}
	*/

};
