using System.Collections.Generic;
using System.Linq;

public class AdminService
{
    private readonly List<Admin> _admins = new List<Admin>();

    public void Register(Admin admin)
    {
        _admins.Add(admin);
    }

    public bool Login(string username, string password)
    {
        return _admins.Any(a => a.Username == username && a.Password == password);
    }
}
