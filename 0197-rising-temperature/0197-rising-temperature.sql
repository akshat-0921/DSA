Select w2.id as Id from Weather w1 Join Weather w2 WHERE w2.temperature > w1.temperature AND
subdate(w2.recordDate, 1) = w1.recordDate;