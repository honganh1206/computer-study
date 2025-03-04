```ad-info
title: Definitions
- A design pattern commonly used in software development to **abstract the data access logic** and **provide a clean separation between the business logic and the underlying data storage**
- What it involves:
	- **Create a repository interface** to interact with entities
	- **Implement that interface** in a concrete repository class

```

```csharp
using System;
using System.Collections.Generic;
using System.Linq;

// Entity representing a user
public class User
{
    public int Id { get; set; }
    public string Username { get; set; }
    public string Email { get; set; }
}

// Repository interface for managing User entities
public interface IUserRepository
{
    User GetById(int id);
    IEnumerable<User> GetAll();
    void Add(User user);
    void Update(User user);
    void Delete(int id);
}

// Concrete implementation of the User Repository
public class UserRepository : IUserRepository
{
    // In a real-world scenario, this is where you would interact with a database.
    // For simplicity, we'll just use an in-memory list in this example.
    private readonly List<User> users = new List<User>();

    public User GetById(int id)
    {
        return users.FirstOrDefault(user => user.Id == id);
    }

    public IEnumerable<User> GetAll()
    {
        return users.ToList();
    }

    public void Add(User user)
    {
        users.Add(user);
    }

    public void Update(User user)
    {
        // In a real-world scenario, you might need to implement logic to update the user.
        // For simplicity, we'll just mark it as updated.
    }

    public void Delete(int id)
    {
        // In a real-world scenario, you might need to implement logic to delete the user.
        // For simplicity, we'll remove the user with the specified ID.
        var userToRemove = users.FirstOrDefault(user => user.Id == id);
        if (userToRemove != null)
        {
            users.Remove(userToRemove);
        }
    }
}

class Program
{
    static void Main()
    {
        // Creating an instance of the repository
        IUserRepository userRepository = new UserRepository();

        // Performing operations using the repository
        var user1 = new User { Id = 1, Username = "john_doe", Email = "john@example.com" };
        var user2 = new User { Id = 2, Username = "jane_doe", Email = "jane@example.com" };

        userRepository.Add(user1);
        userRepository.Add(user2);

        Console.WriteLine("All Users:");
        foreach (var user in userRepository.GetAll())
        {
            Console.WriteLine($"User ID: {user.Id}, Username: {user.Username}, Email: {user.Email}");
        }

        var userToUpdate = userRepository.GetById(1);
        if (userToUpdate != null)
        {
            userToUpdate.Email = "john_updated@example.com";
            userRepository.Update(userToUpdate);
        }

        Console.WriteLine("\nAfter Update:");
        foreach (var user in userRepository.GetAll())
        {
            Console.WriteLine($"User ID: {user.Id}, Username: {user.Username}, Email: {user.Email}");
        }

        userRepository.Delete(2);

        Console.WriteLine("\nAfter Delete:");
        foreach (var user in userRepository.GetAll())
        {
            Console.WriteLine($"User ID: {user.Id}, Username: {user.Username}, Email: {user.Email}");
        }
    }
}

```