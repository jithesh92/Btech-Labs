(defun insert (target list)
  (if (null list)
    (cons target nil)
    (if (<= target (first list))
      (cons target list)
      (cons (first list) (insert target (rest list))))))
 
(defun insertSort (myList)
  (if (null myList)
    nil
    (insert (first myList) (insertSort (rest myList)))))


(defun main()
    (progn(princ "Enter the list")
          (setf q (read))
          (print (insertSort q))))
(main)
