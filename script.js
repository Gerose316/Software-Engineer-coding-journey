

const products = [
    { id: 1, name: 'Classic Denim Jacket', brand: 'Vogue Haven', price: 89.99, category: 'women', subcategory: 'jackets', shopifyUrl: 'https://your-store.myshopify.com/products/classic-denim-jacket', images: ['https://images.unsplash.com/photo-1551028719-00167b16eac5?w=600&h=800&fit=crop'], sizes: ['XS', 'S', 'M', 'L', 'XL'] },
    { id: 2, name: 'Summer Dress', brand: 'Vogue Haven', price: 79.99, category: 'women', subcategory: 'dresses', shopifyUrl: 'https://your-store.myshopify.com/products/summer-dress', images: ['https://images.unsplash.com/photo-1595777457583-95e059d581b8?w=600&h=800&fit=crop'], sizes: ['XS', 'S', 'M', 'L', 'XL', 'XXL'] },
    { id: 3, name: 'Leather Ankle Boots', brand: 'Vogue Haven', price: 159.99, category: 'women', subcategory: 'shoes', shopifyUrl: 'https://your-store.myshopify.com/products/leather-boots', images: ['https://images.unsplash.com/photo-1543163521-1bf539c55dd2?w=600&h=800&fit=crop'], sizes: ['5', '6', '7', '8', '9', '10'] },
    { id: 4, name: 'Cotton T-Shirt', brand: 'Vogue Haven', price: 34.99, category: 'men', subcategory: 'tshirts', shopifyUrl: 'https://your-store.myshopify.com/products/casual-tshirt', images: ['https://images.unsplash.com/photo-1521572163474-6864f9cf17ab?w=600&h=800&fit=crop'], sizes: ['S', 'M', 'L', 'XL', 'XXL'] },
    { id: 5, name: 'Tailored Blazer', brand: 'Vogue Haven', price: 249.99, category: 'men', subcategory: 'jackets', shopifyUrl: 'https://your-store.myshopify.com/products/suit-jacket', images: ['https://images.unsplash.com/photo-1594938298603-c8148c4dae35?w=600&h=800&fit=crop'], sizes: ['S', 'M', 'L', 'XL', 'XXL'] },
    { id: 6, name: 'Slim Fit Jeans', brand: 'Vogue Haven', price: 69.99, category: 'men', subcategory: 'pants', shopifyUrl: 'https://your-store.myshopify.com/products/slim-jeans', images: ['https://images.unsplash.com/photo-1542272604-787c3835535d?w=600&h=800&fit=crop'], sizes: ['28', '30', '32', '34', '36', '38'] },
    { id: 7, name: 'Silk Blouse', brand: 'Vogue Haven', price: 94.99, category: 'women', subcategory: 'tops', shopifyUrl: 'https://your-store.myshopify.com/products/silk-blouse', images: ['https://images.unsplash.com/photo-1564859228273-274232fdb516?w=600&h=800&fit=crop'], sizes: ['XS', 'S', 'M', 'L', 'XL'] },
    { id: 8, name: 'Knit Sweater', brand: 'Vogue Haven', price: 119.99, category: 'women', subcategory: 'sweaters', shopifyUrl: 'https://your-store.myshopify.com/products/knit-sweater', images: ['https://images.unsplash.com/photo-1576566588028-4147f3842f27?w=600&h=800&fit=crop'], sizes: ['XS', 'S', 'M', 'L', 'XL'] },
    { id: 9, name: 'Cargo Pants', brand: 'Vogue Haven', price: 79.99, category: 'men', subcategory: 'pants', shopifyUrl: 'https://your-store.myshopify.com/products/cargo-pants', images: ['https://images.unsplash.com/photo-1473966968600-fa801b869a1a?w=600&h=800&fit=crop'], sizes: ['28', '30', '32', '34', '36', '38'] },
    { id: 10, name: 'Wool Coat', brand: 'Vogue Haven', price: 299.99, category: 'women', subcategory: 'coats', shopifyUrl: 'https://your-store.myshopify.com/products/wool-coat', images: ['https://images.unsplash.com/photo-1539533018447-63fcce2678e3?w=600&h=800&fit=crop'], sizes: ['XS', 'S', 'M', 'L', 'XL'] },
    { id: 11, name: 'Leather Jacket', brand: 'Vogue Haven', price: 329.99, category: 'men', subcategory: 'jackets', shopifyUrl: 'https://your-store.myshopify.com/products/leather-jacket', images: ['https://images.unsplash.com/photo-1551028719-00167b16eac5?w=600&h=800&fit=crop'], sizes: ['S', 'M', 'L', 'XL', 'XXL'] },
    { id: 12, name: 'Pleated Skirt', brand: 'Vogue Haven', price: 59.99, category: 'women', subcategory: 'skirts', shopifyUrl: 'https://your-store.myshopify.com/products/pleated-skirt', images: ['https://images.unsplash.com/photo-1583496661160-fb5886a0aaaa?w=600&h=800&fit=crop'], sizes: ['XS', 'S', 'M', 'L', 'XL'] },
    { id: 13, name: 'Polo Shirt', brand: 'Vogue Haven', price: 49.99, category: 'men', subcategory: 'tshirts', shopifyUrl: 'https://your-store.myshopify.com/products/polo-shirt', images: ['https://images.unsplash.com/photo-1586790170083-2f9ceadc732d?w=600&h=800&fit=crop'], sizes: ['S', 'M', 'L', 'XL', 'XXL'] },
    { id: 14, name: 'Maxi Dress', brand: 'Vogue Haven', price: 129.99, category: 'women', subcategory: 'dresses', shopifyUrl: 'https://your-store.myshopify.com/products/maxi-dress', images: ['https://images.unsplash.com/photo-1572804013309-59a88b7e92f1?w=600&h=800&fit=crop'], sizes: ['XS', 'S', 'M', 'L', 'XL'] },
    { id: 15, name: 'Chino Pants', brand: 'Vogue Haven', price: 74.99, category: 'men', subcategory: 'pants', shopifyUrl: 'https://your-store.myshopify.com/products/chino-pants', images: ['https://images.unsplash.com/photo-1624378439575-d8705ad7ae80?w=600&h=800&fit=crop'], sizes: ['28', '30', '32', '34', '36', '38'] },
    { id: 16, name: 'Cardigan', brand: 'Vogue Haven', price: 89.99, category: 'women', subcategory: 'sweaters', shopifyUrl: 'https://your-store.myshopify.com/products/cardigan', images: ['https://images.unsplash.com/photo-1591369822096-ffd140ec948f?w=600&h=800&fit=crop'], sizes: ['XS', 'S', 'M', 'L', 'XL'] },
    { id: 17, name: 'Basic White Tee', brand: 'Vogue Haven', price: 29.99, category: 'women', subcategory: 'tshirts', shopifyUrl: 'https://your-store.myshopify.com/products/white-tee', images: ['https://images.unsplash.com/photo-1562157873-818bc0726f68?w=600&h=800&fit=crop'], sizes: ['XS', 'S', 'M', 'L', 'XL'] },
    { id: 18, name: 'Graphic T-Shirt', brand: 'Vogue Haven', price: 39.99, category: 'women', subcategory: 'tshirts', shopifyUrl: 'https://your-store.myshopify.com/products/graphic-tee', images: ['https://images.unsplash.com/photo-1618354691373-d851c5c3a990?w=600&h=800&fit=crop'], sizes: ['XS', 'S', 'M', 'L', 'XL'] },
    { id: 19, name: 'Wide Leg Pants', brand: 'Vogue Haven', price: 89.99, category: 'women', subcategory: 'pants', shopifyUrl: 'https://your-store.myshopify.com/products/wide-leg-pants', images: ['https://images.unsplash.com/photo-1594633313593-bab3825d0caf?w=600&h=800&fit=crop'], sizes: ['XS', 'S', 'M', 'L', 'XL'] },
    { id: 20, name: 'High Waist Trousers', brand: 'Vogue Haven', price: 79.99, category: 'women', subcategory: 'pants', shopifyUrl: 'https://your-store.myshopify.com/products/trousers', images: ['https://images.unsplash.com/photo-1506629082955-511b1aa562c8?w=600&h=800&fit=crop'], sizes: ['XS', 'S', 'M', 'L', 'XL'] },
    { id: 21, name: 'V-Neck Tee', brand: 'Vogue Haven', price: 34.99, category: 'men', subcategory: 'tshirts', shopifyUrl: 'https://your-store.myshopify.com/products/vneck-tee', images: ['https://images.unsplash.com/photo-1622445275463-afa2ab738c34?w=600&h=800&fit=crop'], sizes: ['S', 'M', 'L', 'XL', 'XXL'] },
    { id: 22, name: 'Crew Neck T-Shirt', brand: 'Vogue Haven', price: 32.99, category: 'men', subcategory: 'tshirts', shopifyUrl: 'https://your-store.myshopify.com/products/crew-tee', images: ['https://images.unsplash.com/photo-1583743814966-8936f5b7be1a?w=600&h=800&fit=crop'], sizes: ['S', 'M', 'L', 'XL', 'XXL'] }
];

let currentCategory = 'all';
let currentGender = 'women';
let heightUnit = 'cm';
let weightUnit = 'kg';
let searchQuery = '';
let priceFilters = [];
let categoryFilters = ['all'];
let currentSort = 'featured';
let filteredProducts = [...products];

// Page Navigation
function showHomePage() {
    document.getElementById('homePage').classList.add('active');
    document.getElementById('productDetailPage').classList.remove('active');
    document.getElementById('sizeCalculatorPage').classList.remove('active');
    window.scrollTo(0, 0);
}

function scrollToSection(id) {
    showHomePage();
    setTimeout(() => {
        document.getElementById(id).scrollIntoView({ behavior: 'smooth' });
    }, 100);
}

function showSizeCalculator() {
    document.getElementById('homePage').classList.remove('active');
    document.getElementById('productDetailPage').classList.remove('active');
    document.getElementById('sizeCalculatorPage').classList.add('active');
    window.scrollTo(0, 0);
    selectGender('women');
}

// Search Functionality
function handleSearch(event) {
    searchQuery = event.target.value.toLowerCase();
    if (event.key === 'Enter') {
        filterAndRenderProducts();
        scrollToSection('products');
    } else {
        // Real-time search
        filterAndRenderProducts();
    }
}

// Filter Products
function filterCategory(category) {
    currentCategory = category;
    categoryFilters = [category];
    
    // Update checkbox states
    document.querySelectorAll('.filter-checkbox input').forEach(cb => {
        cb.checked = cb.value === category;
    });
    
    filterAndRenderProducts();
    scrollToSection('products');
}

function updateFilters() {
    const checkboxes = document.querySelectorAll('.filter-checkbox input:checked');
    categoryFilters = Array.from(checkboxes).map(cb => cb.value);
    
    if (categoryFilters.length === 0 || categoryFilters.includes('all')) {
        categoryFilters = ['all'];
    }
    
    filterAndRenderProducts();
}

function updatePriceFilter() {
    const checkboxes = document.querySelectorAll('.filter-section:nth-child(2) .filter-checkbox input:checked');
    priceFilters = Array.from(checkboxes).map(cb => cb.value);
    filterAndRenderProducts();
}

function sortProducts(sortType) {
    currentSort = sortType;
    filterAndRenderProducts();
}

function filterAndRenderProducts() {
    // Start with all products
    filteredProducts = [...products];
    
    // Apply category filter
    if (!categoryFilters.includes('all')) {
        filteredProducts = filteredProducts.filter(p => {
            // Check if any selected filter matches
            return categoryFilters.some(filter => {
                // Handle compound filters like 'women-tshirts'
                if (filter.includes('-')) {
                    const [cat, subcat] = filter.split('-');
                    return p.category === cat && p.subcategory === subcat;
                }
                // Handle simple category filters like 'women' or 'men'
                return p.category === filter;
            });
        });
    }
    
    // Apply search filter
    if (searchQuery) {
        filteredProducts = filteredProducts.filter(p =>
            p.name.toLowerCase().includes(searchQuery) ||
            p.brand.toLowerCase().includes(searchQuery) ||
            p.category.toLowerCase().includes(searchQuery)
        );
    }
    
    // Apply price filter
    if (priceFilters.length > 0) {
        filteredProducts = filteredProducts.filter(p => {
            return priceFilters.some(range => {
                if (range === '0-50') return p.price < 50;
                if (range === '50-100') return p.price >= 50 && p.price < 100;
                if (range === '100-200') return p.price >= 100 && p.price < 200;
                if (range === '200+') return p.price >= 200;
                return false;
            });
        });
    }
    
    // Apply sorting
    if (currentSort === 'price-low') {
        filteredProducts.sort((a, b) => a.price - b.price);
    } else if (currentSort === 'price-high') {
        filteredProducts.sort((a, b) => b.price - a.price);
    } else if (currentSort === 'newest') {
        filteredProducts.sort((a, b) => b.id - a.id);
    }
    
    renderProducts();
}

// Render Products
function renderProducts() {
    const grid = document.getElementById('productsGrid');
    const productCount = document.getElementById('productCount');
    
    productCount.textContent = `${filteredProducts.length} item${filteredProducts.length !== 1 ? 's' : ''}`;
    
    if (filteredProducts.length === 0) {
        grid.innerHTML = '<div style="grid-column: 1/-1; text-align: center; padding: 60px; color: #666;"><h3>No products found</h3><p>Try adjusting your filters or search term</p></div>';
        return;
    }
    
    grid.innerHTML = filteredProducts.map(p => `
        <div class="product-card" onclick="showProductDetail(${p.id})">
            <div class="product-image-wrapper">
                <img src="${p.images[0]}" alt="${p.name}">
                ${p.price < 50 ? '<div class="product-badge">SALE</div>' : ''}
            </div>
            <div class="product-info">
                <div class="product-brand">${p.brand}</div>
                <div class="product-name">${p.name}</div>
                <div class="product-price">$${p.price.toFixed(2)}</div>
            </div>
        </div>
    `).join('');
}

// Product Detail
function showProductDetail(id) {
    const product = products.find(p => p.id === id);
    
    document.getElementById('breadcrumbCategory').textContent = product.category.toUpperCase();
    document.getElementById('breadcrumbProduct').textContent = product.name;
    
    const detailHTML = `
        <div class="product-detail-gallery">
            ${product.images.map(img => `
                <div class="product-detail-image">
                    <img src="${img}" alt="${product.name}">
                </div>
            `).join('')}
        </div>
        <div class="product-detail-info">
            <div class="product-detail-brand">${product.brand.toUpperCase()}</div>
            <h1 class="product-detail-title">${product.name}</h1>
            <div class="product-detail-price">$${product.price.toFixed(2)}</div>
            <div class="product-detail-description">
                Premium quality ${product.name.toLowerCase()} crafted with attention to detail. 
                Perfect for any occasion, this piece combines style with comfort.
            </div>
            
            <div class="size-selector">
                <h4>SELECT SIZE</h4>
                <div class="size-options">
                    ${product.sizes.map(size => `
                        <div class="size-option">${size}</div>
                    `).join('')}
                </div>
                <a class="size-guide-link" onclick="event.stopPropagation(); showSizeCalculator()">
                    Size Guide
                </a>
            </div>
            
            <button class="shopify-cta-large" onclick="window.open('${product.shopifyUrl}', '_blank')">
                ADD TO BAG
            </button>
        </div>
    `;
    
    document.getElementById('productDetailContent').innerHTML = detailHTML;
    document.getElementById('homePage').classList.remove('active');
    document.getElementById('productDetailPage').classList.add('active');
    document.getElementById('sizeCalculatorPage').classList.remove('active');
    window.scrollTo(0, 0);
}

// Size Calculator
function selectGender(gender) {
    currentGender = gender;
    document.getElementById('womenBtn').classList.toggle('active', gender === 'women');
    document.getElementById('menBtn').classList.toggle('active', gender === 'men');
    renderMeasurementForm();
}

function renderMeasurementForm() {
    const form = document.getElementById('measurementForm');
    
    const formHTML = `
        <h3>${currentGender === 'women' ? "WOMEN'S" : "MEN'S"} MEASUREMENTS</h3>
        
        <div class="form-group">
            <label>HEIGHT</label>
            <div class="input-wrapper">
                <input type="number" id="height" placeholder="Enter height" step="0.1" min="0">
                <button class="unit-toggle" onclick="toggleHeightUnit()">
                    ${heightUnit === 'cm' ? 'CM' : 'IN'}
                </button>
            </div>
        </div>
        
        <div class="form-group">
            <label>WEIGHT</label>
            <div class="input-wrapper">
                <input type="number" id="weight" placeholder="Enter weight" step="0.1" min="0">
                <button class="unit-toggle" onclick="toggleWeightUnit()">
                    ${weightUnit === 'kg' ? 'KG' : 'LBS'}
                </button>
            </div>
        </div>
        
        ${currentGender === 'women' ? `
            <div class="form-group">
                <label>BUST (CM)</label>
                <input type="number" id="bust" placeholder="Measure around fullest part" step="0.1" min="0">
            </div>
            
            <div class="form-group">
                <label>WAIST (CM)</label>
                <input type="number" id="waist" placeholder="Measure around natural waistline" step="0.1" min="0">
            </div>
            
            <div class="form-group">
                <label>HIPS (CM)</label>
                <input type="number" id="hips" placeholder="Measure around fullest part" step="0.1" min="0">
            </div>
        ` : `
            <div class="form-group">
                <label>CHEST (CM)</label>
                <input type="number" id="chest" placeholder="Measure around fullest part" step="0.1" min="0">
            </div>
            
            <div class="form-group">
                <label>WAIST (CM)</label>
                <input type="number" id="waist" placeholder="Measure around natural waistline" step="0.1" min="0">
            </div>
            
            <div class="form-group">
                <label>SHOULDER WIDTH (CM)</label>
                <input type="number" id="shoulder" placeholder="Measure across shoulders" step="0.1" min="0">
            </div>
        `}
        
        <button class="calculate-btn" onclick="calculateSize()">CALCULATE SIZE</button>
    `;
    
    form.innerHTML = formHTML;
    document.getElementById('sizeResults').classList.add('hidden');
    document.getElementById('sizeResults').classList.remove('active');
}

function toggleHeightUnit() {
    const input = document.getElementById('height');
    const value = parseFloat(input.value);
    
    if (value) {
        if (heightUnit === 'cm') {
            input.value = (value / 2.54).toFixed(1);
            heightUnit = 'inches';
        } else {
            input.value = (value * 2.54).toFixed(1);
            heightUnit = 'cm';
        }
    } else {
        heightUnit = heightUnit === 'cm' ? 'inches' : 'cm';
    }
    
    renderMeasurementForm();
}

function toggleWeightUnit() {
    const input = document.getElementById('weight');
    const value = parseFloat(input.value);
    
    if (value) {
        if (weightUnit === 'kg') {
            input.value = (value * 2.20462).toFixed(1);
            weightUnit = 'lbs';
        } else {
            input.value = (value / 2.20462).toFixed(1);
            weightUnit = 'kg';
        }
    } else {
        weightUnit = weightUnit === 'kg' ? 'lbs' : 'kg';
    }
    
    renderMeasurementForm();
}

function calculateSize() {
    const height = parseFloat(document.getElementById('height').value);
    const weight = parseFloat(document.getElementById('weight').value);
    
    if (!height || !weight) {
        alert('Please enter your height and weight');
        return;
    }
    
    const heightCm = heightUnit === 'cm' ? height : height * 2.54;
    const weightKg = weightUnit === 'kg' ? weight : weight / 2.20462;
    
    let size, description, recommendations;
    
    if (currentGender === 'women') {
        const bust = parseFloat(document.getElementById('bust').value);
        const waist = parseFloat(document.getElementById('waist').value);
        const hips = parseFloat(document.getElementById('hips').value);
        
        if (!bust || !waist || !hips) {
            alert('Please enter all measurements');
            return;
        }
        
        if (bust <= 84 && waist <= 66 && hips <= 92) {
            size = 'XS';
            description = 'Extra Small';
        } else if (bust <= 89 && waist <= 71 && hips <= 97) {
            size = 'S';
            description = 'Small';
        } else if (bust <= 94 && waist <= 76 && hips <= 102) {
            size = 'M';
            description = 'Medium';
        } else if (bust <= 99 && waist <= 81 && hips <= 107) {
            size = 'L';
            description = 'Large';
        } else if (bust <= 106 && waist <= 89 && hips <= 114) {
            size = 'XL';
            description = 'Extra Large';
        } else {
            size = 'XXL';
            description = 'Double Extra Large';
        }
        
        recommendations = [
            `Height: ${heightCm.toFixed(0)} cm`,
            `Weight: ${weightKg.toFixed(1)} kg`,
            `Bust: ${bust} cm`,
            `Waist: ${waist} cm`,
            `Hips: ${hips} cm`
        ];
        
    } else {
        const chest = parseFloat(document.getElementById('chest').value);
        const waist = parseFloat(document.getElementById('waist').value);
        const shoulder = parseFloat(document.getElementById('shoulder').value);
        
        if (!chest || !waist || !shoulder) {
            alert('Please enter all measurements');
            return;
        }
        
        if (chest <= 91 && waist <= 76) {
            size = 'S';
            description = 'Small';
        } else if (chest <= 99 && waist <= 84) {
            size = 'M';
            description = 'Medium';
        } else if (chest <= 107 && waist <= 91) {
            size = 'L';
            description = 'Large';
        } else if (chest <= 117 && waist <= 101) {
            size = 'XL';
            description = 'Extra Large';
        } else {
            size = 'XXL';
            description = 'Double Extra Large';
        }
        
        recommendations = [
            `Height: ${heightCm.toFixed(0)} cm`,
            `Weight: ${weightKg.toFixed(1)} kg`,
            `Chest: ${chest} cm`,
            `Waist: ${waist} cm`,
            `Shoulder: ${shoulder} cm`
        ];
    }
    
    displaySizeResults(size, description, recommendations);
}

function displaySizeResults(size, description, recommendations) {
    const resultsDiv = document.getElementById('sizeResults');
    
    const resultsHTML = `
        <div class="result-size">${size}</div>
        <div class="result-title">YOUR RECOMMENDED SIZE</div>
        <div class="result-description">${description}</div>
        
        <div class="result-details">
            <h4>YOUR MEASUREMENTS</h4>
            <ul>
                ${recommendations.map(rec => `<li>${rec}</li>`).join('')}
            </ul>
        </div>
        
        <button class="calculate-btn" style="margin-top: 20px;" onclick="window.open('https://your-store.myshopify.com', '_blank')">
            SHOP SIZE ${size}
        </button>
    `;
    
    resultsDiv.innerHTML = resultsHTML;
    resultsDiv.classList.remove('hidden');
    resultsDiv.classList.add('active');
}

// Initialize
filterAndRenderProducts();
