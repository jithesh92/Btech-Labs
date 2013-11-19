(defun bubble-sort (lst)
  (loop repeat (1- (length lst)) do
    (loop for ls on lst while (rest ls) do
      (when (> (first ls) (second ls))
        (rotatef (first ls) (second ls)))))
  lst)

(defun main()
    (progn(princ "Enter the list")
          (setf q (read))
          (print (bubble-sort q))))
(main)
