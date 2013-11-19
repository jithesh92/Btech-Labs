(defun qsort (a)
	(if (null a) nil
	(let* ((x (car a)) (r (cdr a)) (fn (lambda (b) (< b x))))
	(append (qsort (remove-if-not fn r)) (list x)  (qsort(remove-if fn r))))))

(defun main()
    (progn(princ "Enter the list")
          (setf q (read))
          (print (qsort q))))
(main)
