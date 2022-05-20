PROGRAM Main
  use, intrinsic :: iso_fortran_env, only: dp=>real64
  implicit none
  real(dp)  :: u, i_b, f_b, i_b2, f_b2
  integer  :: i, j, count_, contador
  integer, parameter  :: n = 4
  real(dp), dimension (n,n)  ::  A
  real(dp), dimension (n)  ::  x, b, b2
  real(dp)  ::  matrix_lenght_r
  CHARACTER(len=32)  ::  arg
  real(dp) :: intl

  print *, "N, GB, t1, t2"

  DO count_ = 1,3
    CALL get_command_argument(count_, arg)
    IF (LEN_TRIM(arg) == 0) EXIT
    !WRITE (*,*) TRIM(arg)
    !write(*, '(a35)', advance = "no") arg
    read( arg, '(d10.0)' )  intl
    DO contador = 1,10
      matrix_lenght_r = matrix_lenght(floor(intl))
      !write(*, '(a35)', advance = "no") floor(matrix_lenght_r)
    ! Matriz A
      do i = 1, n
        do j = 1, n
          call random_number(u)
          A(i,j) = u
        end do
      end do
    
    
      ! Vetor x
      do i = 1, n
        call random_number(u)
        x(i) = u
      end do
      
    
    ! Metodo 1
    
      ! Vetor b
      b = 0.0
      call cpu_time(i_b)
      do i = 1, n
        do j = 1, n
          b(i) = b(i) + A(i,j) * x(j)
        end do
      end do
      call cpu_time(f_b)
    
    
    ! Metodo 2
    
      ! Vetor b2
      b2 = 0.0
      call cpu_time(i_b2)
      do j = 1, n
        do i = 1, n
          b2(i) = b2(i) + A(i,j) * x(j)
        end do
      end do
      call cpu_time(f_b2)
    
    
      ! ------------------------------------------------------ Results time
      print '(I0, ",", I0, ",", f10.6, ",", f10.6)', n, floor(intl), f_b - i_b, f_b2 - i_b2
    END DO
  END DO

contains
  
  real(dp) function matrix_lenght(ramgb)
    implicit none
    integer:: a, b, ramgb, i
    real(dp) :: c, discriminant, x1, x2

    a = 1
    b = 2
    matrix_lenght = 0
    
    c = ramgb*8
    c = c/64*(-1)
    c = c*1000000000   

    discriminant = b**2 - 4*a*c
    
    if ( discriminant>0 ) then
    
      x1 = ( -b + sqrt(discriminant)) / (2 * a)
      x2 = ( -b - sqrt(discriminant)) / (2 * a)
      if (x1>x2) then
        matrix_lenght = x1
      else if (x2>x1) then
        matrix_lenght = x2
      end if
    else if ( discriminant==0 ) then
      x1 = - b / (2 * a)
      matrix_lenght = x1
    end if
  end function matrix_lenght

END PROGRAM Main