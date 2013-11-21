
(defun ismember(a l)
(cond
((null l)nil)
((= a(car l))t)
(t(ismember a (cdr l)))))


(defun main()
(princ "Enter set a: ")
(setf a(read))
(princ "Enter set b: ")
(setf b(read))
(loop
(format t "~%Menu~%1.Union~%2.Intersection~%3.Membership in A~%4.membership in B~%5.Set Difference~%6.Exit~%Enter the choice: ")
(setf c(read))
(cond
((= c 1)(print(union a b)))
((= c 2)(print(intersection a b)))
((= c 3)(progn(format t "~%Enter the element")(setf l(read)) (print(ismember l a))))
((= c 4)(progn(format t "~%Enter the element")(setf l(read)) (print(ismember l b))))
((= c 5)(print(set-difference a b)))
((= c 6)(return)))))
(main)

