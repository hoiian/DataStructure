== Knight's Tour ==
Following the method provided by textbook.(Warnsdorff's rule)
Using the arrays ktmove1[] and ktmove2[] to save the legal (horizontal and vertical) moves for a knight.
Then test1,test2 see if the next step out of the border or not, for each posibility, save it into nexti[l], nextj[l], the total numbers of posibility is saved into npos.
If npos == 0, means there are no more next step is posible,
npos == 1, means there are just one next step can be implemented,
for npos > 1, we have to see the posibility of (next1[l],nextj[l]) and see which step is fewest as the chosen one to implement.
Running a loop with n*n steps can slove the problam eventually.