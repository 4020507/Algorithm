select a.id from Weather  as a, Weather as b where a.Temperature > b.Temperature
and DATEDIFF(a.recordDate,b.recordDate) = 1
