using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;

namespace GenerativeAIWebsite.Controllers
{
    public class AIImagesController : Controller
    {
        private readonly ApplicationDbContext _context;

        public AIImagesController(ApplicationDbContext context)
        {
            _context = context;
        }

        // GET: AIImages
        public async Task<IActionResult> Index()
        {
            return View(await _context.AIImages.ToListAsync());
        }

        // GET: AIImages/Details/5
        public async Task<IActionResult> Details(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var aIImage = await _context.AIImages
                .FirstOrDefaultAsync(m => m.Id == id);
            if (aIImage == null)
            {
                return NotFound();
            }

            return View(aIImage);
        }

        // GET: AIImages/Create
        public IActionResult Create()
        {
            return View();
        }

        // POST: AIImages/Create
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Create([Bind("Id,Prompt,ImageGenerator,Filename,Like,canIncreaseLike,UploadedFile")] AIImage aIImage)
        {
            if (ModelState.IsValid)
            {
                // Handle file upload if there is a file
                if (aIImage.UploadedFile != null && aIImage.UploadedFile.Length > 0)
                {
                    // Validate file type (e.g., only allow jpg, png, gif)
                    var allowedExtensions = new[] { ".jpg", ".jpeg", ".png", ".gif" };
                    var fileExtension = Path.GetExtension(aIImage.UploadedFile.FileName).ToLower();

                    if (!allowedExtensions.Contains(fileExtension))
                    {
                        ModelState.AddModelError("UploadedFile", "Invalid file type. Only JPG, JPEG, PNG, and GIF files are allowed.");
                        return View(aIImage); // Return the view with the validation error
                    }

                    // Set the file path to save the file
                    var filePath = Path.Combine(Directory.GetCurrentDirectory(), "wwwroot/uploads", aIImage.UploadedFile.FileName);

                    // Create the upload directory if it does not exist
                    var uploadDirectory = Path.Combine(Directory.GetCurrentDirectory(), "wwwroot/uploads");
                    if (!Directory.Exists(uploadDirectory))
                    {
                        Directory.CreateDirectory(uploadDirectory);
                    }

                    // Save the uploaded file to the server
                    using (var stream = new FileStream(filePath, FileMode.Create))
                    {
                        await aIImage.UploadedFile.CopyToAsync(stream);
                    }

                    // Store the file name in the Filename field
                    aIImage.Filename = aIImage.UploadedFile.FileName;
                }

                // Set the UploadDate to the current date and time
                aIImage.UploadDate = DateTime.Now;

                // Initialize the Like count to 0
                aIImage.Like = 0;

                // Add the AIImage model to the database and save changes
                _context.Add(aIImage);
                await _context.SaveChangesAsync();

                // Redirect to the Index action
                return RedirectToAction(nameof(Index));
            }

            // If the model state is invalid, return the view with the model
            return View(aIImage);
        }


        // GET: AIImages/Edit/5
        public async Task<IActionResult> Edit(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var aIImage = await _context.AIImages.FindAsync(id);
            if (aIImage == null)
            {
                return NotFound();
            }
            return View(aIImage);
        }

        // POST: AIImages/Edit/5
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Edit(int id, [Bind("Id,Prompt,ImageGenerator,UploadDate,Filename,Like,canIncreaseLike")] AIImage aIImage)
        {
            if (id != aIImage.Id)
            {
                return NotFound();
            }

            if (ModelState.IsValid)
            {
                try
                {
                    _context.Update(aIImage);
                    await _context.SaveChangesAsync();
                }
                catch (DbUpdateConcurrencyException)
                {
                    if (!AIImageExists(aIImage.Id))
                    {
                        return NotFound();
                    }
                    else
                    {
                        throw;
                    }
                }
                return RedirectToAction(nameof(Index));
            }
            return View(aIImage);
        }

        // GET: AIImages/Delete/5
        public async Task<IActionResult> Delete(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var aIImage = await _context.AIImages
                .FirstOrDefaultAsync(m => m.Id == id);
            if (aIImage == null)
            {
                return NotFound();
            }

            return View(aIImage);
        }

        // POST: AIImages/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> DeleteConfirmed(int id)
        {
            var aIImage = await _context.AIImages.FindAsync(id);
            if (aIImage != null)
            {
                _context.AIImages.Remove(aIImage);
            }

            await _context.SaveChangesAsync();
            return RedirectToAction(nameof(Index));
        }

        private bool AIImageExists(int id)
        {
            return _context.AIImages.Any(e => e.Id == id);
        }
    }
}

