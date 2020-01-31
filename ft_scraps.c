// int	ft_signed_width(t_flag flags, int decimal, int count)
// {
// 	int rtn;

// 	rtn = 0;
// 	if (flags.precision >= count && flags.precision < flags.width)
// 	{
// 		rtn = ft_fix_field(flags.width - flags.precision - 1, ' ');
// 		ft_putchar_fd('-', 1);
// 		rtn += ft_fix_field(flags.precision - count + 1, '0');
// 	}
// 	else if (flags.precision < count)
// 	{
// 		rtn = ft_fix_field(flags.width - count, ' ');
// 		ft_putchar_fd('-', 1);
// 	}
// 	return (rtn);
// }

// int	ft_neg_sign(int decimal, t_flag flags, int count, int rtn)
// {
// 	// if (flags.minus == 1 || flags.width > 0)
// 	// 	rtn = ft_neg_width(flags, decimal, count);
// 	if (flags.precision >= count)
// 	{
// 		ft_putchar_fd('-', 1);
// 		rtn = ft_fix_field(flags.precision - count + 1, '0');
// 	}
// 	else if (flags.precision < count)
// 		ft_putchar_fd('-', 1);
// 	return (rtn);
// }

// int	ft_signed_precision(int decimal, int count, t_flag flags)
// {
// 	int rtn;

// 	rtn = 0;
	// if (decimal < 0)
	// {
	// 	rtn = ft_neg_sign(decimal, flags, count, rtn);
	// 	decimal *= -1;
	// }
// 	if (decimal == 0 && flags.precision == 0)
// 		return (rtn);
// 	if (flags.width >= 0 && flags.precision <= count)
// 		rtn = ft_fix_field(flags.width - count, ' ');
// 	else if (flags.width > 0 && flags.precision > count &&
// 		flags.precision < flags.width)
// 	{
// 		rtn = ft_fix_field(flags.width - flags.precision, ' ');
// 		rtn += ft_fix_field(flags.precision - count, '0');
// 	}
// 	else if (flags.precision > count)
// 		rtn = ft_fix_field(flags.precision - count, '0');
// 	ft_putnbr_fd(decimal, 1);
// 	rtn += count;
// 	return (rtn);
// }

// int	ft_signed_field(int count, int decimal, t_flag flags)
// {
// 	int rtn;

// 	rtn = 0;
// 	if (flags.minus == 1)
// 	{
// 		ft_putnbr_fd(decimal, 1);
// 		rtn += ft_fix_field(flags.width - count, ' ');
// 		return (rtn);
// 	}
// 	else if (flags.zero == 1)
// 	{
// 		if (decimal < 0)
// 		{
// 			ft_putchar_fd('-', 1);
// 			decimal *= -1;
// 		}
// 		rtn += ft_fix_field(flags.width - count, '0');
// 	}
// 	else if (flags.width >= 0)
// 		rtn = ft_fix_field(flags.width - count, ' ');
// 	ft_putnbr_fd(decimal, 1);
// 	return (rtn);
// }

//signed_conv
// if (((flags.minus == 1 && flags.width > 0) || (flags.zero == 1 &&
// 		flags.width > 0)) && flags.precision == -1)
// 	{
// 		rtn = ft_signed_field(count, decimal, flags);
// 		rtn += count;
// 	}
// 	else if (flags.period == 0)
// 		rtn = ft_signed_precision(decimal, count, flags);
// 	else if (flags.width >= 0)
// 	{
// 		rtn = ft_signed_field(count, decimal, flags);
// 		rtn += count;
// 	}