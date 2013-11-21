(defun unio(a b)
(cond
((null b)a)
((ismember(car a)b)(unio b(cdr a)))
((cons(car a)(unio b(cdr a))))))

(defun ismember(a l)
(cond
((null l)nil)
((= a(car l))t)
(t(ismember a (cdr l)))))

(defun inter(a b)
(cond
((null b)nil)
((ismember(car b)a)(cons(car b)(inter a(cdr b))))
(t (inter a (cdr b)))))

(defun differ(a b)
(cond
((null a)nil) ((null b) a)
((ismember(car a) b)(differ (cdr a) b))
((cons(car a)(differ (cdr a)b)))))

(defun main()
(princ "Enter set a: ")
(setf a(read))
(princ "Enter set b: ")
(setf b(read))
(loop
(format t "~%Menu~%1.Union~%2.Intersection~%3.Membership in A~%4.membership in B~%5.Set Difference~%6.Exit~%Enter the choice: ")
(setf c(read))
(cond
((= c 1)(print(unio a b)))
((= c 2)(print(inter a b)))
((= c 3)(progn(format t "~%Enter the element")(setf l(read)) (print(ismember l a))))
((= c 4)(progn(format t "~%Enter the element")(setf l(read)) (print(ismember l b))))
((= c 5)(print(differ a b)))
((= c 6)(return)))))
(main)
